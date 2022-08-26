#include "pass1.hpp"

#include "alloca.hpp"
#include "eternal_new.hpp"

#include <iostream> // TODO

using namespace lex;

void pass1_t::uses_type(type_t type)
{
    if(type.name() == TYPE_STRUCT_THUNK || type.name() == TYPE_STRUCT)
        ideps.insert(const_cast<global_t*>(&type.global()));
    else if(has_type_tail(type.name()))
    {
        unsigned const size = type.type_tail_size();
        for(unsigned i = 0; i < size; ++i)
            uses_type(type.type(i));
    }
}

/* TODO
token_t* pass1_t::eternal_expr(expr_temp_t& expr)
{
    if(expr.empty())
        return nullptr;

    // Null-like terminator
    expr.push_back({});

    // Store the expression and return a pointer to it.
    return eternal_new<token_t>(&*expr.begin(), &*expr.end());
}

void pass1_t::convert_expr(token_t* begin)
{
    for(token_t* token = begin; token->type; ++token)
    {
        // Lookup identifiers and replace their '.value'.
        switch(token->type)
        {
        case TOK_ident:
        case TOK_weak_ident:
            if(int const* handle = symbol_table.find(token->pstring.view(source())))
            {
                token->value = *handle;
                token->type = TOK_ident;
                assert(token->signed_() == *handle);
            }
            else
            {
                global_t& g = global_t::lookup(file.source(), token->pstring);
                if(token->type != TOK_weak_ident)
                    ideps.insert(&g);
                else
                    weak_ideps.insert(&g);
                token->type = TOK_global_ident;
                token->set_ptr(&g);
            }
            break;

        case TOK_at:
            if(symbol_table.find(token->pstring.view(source())))
                compiler_error(token->pstring, "Cannot get addresses of local variables.");
            else
            {
                global_t& g = global_t::lookup(file.source(), token->pstring);
                weak_ideps.insert(&g);
                token->set_ptr(&g);
            }
            break;

        case TOK_type_ident:
            {
                global_t& g = global_t::lookup(file.source(), token->pstring);
                ideps.insert(&g);
                token->set_ptr(&g);
            }
            break;

        case TOK_cast_type:
        case TOK_sizeof:
        case TOK_len:
            uses_type(*token->ptr<type_t>());
            break;

        default:
            break;
        }
    }

#ifndef NDEBUG
    for(token_t* token = begin; token->type; ++token)
        assert(token->type != TOK_weak_ident);
#endif
}

token_t const* pass1_t::convert_expr(expr_temp_t& expr)
{
    token_t* ret = eternal_expr(expr);
    convert_expr(ret);
    return ret;
}
*/

ast_node_t const* pass1_t::eternal_expr(ast_node_t const* expr)
{
    // Store the expression and return a pointer to it.
    if(expr)
        return eternal_emplace<ast_node_t>(*expr);
    return nullptr;
}

ast_node_t pass1_t::process_ast(ast_node_t ast)
{
    // Lookup identifiers and replace their '.value'.
    switch(ast.token.type)
    {
    case TOK_ident:
    case TOK_weak_ident:
        if(int const* handle = symbol_table.find(ast.token.pstring.view(source())))
        {
            ast.token.value = *handle;
            ast.token.type = TOK_ident;
            assert(ast.token.signed_() == *handle);
        }
        else
        {
            global_t& g = global_t::lookup(file.source(), ast.token.pstring);
            if(ast.token.type != TOK_weak_ident)
                ideps.insert(&g);
            else
                weak_ideps.insert(&g);
            ast.token.type = TOK_global_ident;
            ast.token.set_ptr(&g);
        }
        break;

        /* TODO
    case TOK_at:
        if(symbol_table.find(ast.token.pstring.view(source())))
            compiler_error(ast.token.pstring, "Cannot get addresses of local variables.");
        else
        {
            global_t& g = global_t::lookup(file.source(), ast.token.pstring);
            weak_ideps.insert(&g);
            ast.token.set_ptr(&g);
        }
        break;
        */

    case TOK_type_ident:
        {
            global_t& g = global_t::lookup(file.source(), ast.token.pstring);
            ideps.insert(&g);
            ast.token.set_ptr(&g);
        }
        break;

    case TOK_cast_type:
    case TOK_sizeof:
    case TOK_len:
        uses_type(*ast.token.ptr<type_t const>());
        break;

    default:
        break;
    }

    return ast;
}

global_t const* pass1_t::at_ident(pstring_t pstring)
{
    if(symbol_table.find(pstring.view(source())))
        return nullptr;
    else
    {
        global_t& g = global_t::lookup(file.source(), pstring);
        weak_ideps.insert(&g);
        return &g;
    }
}

/* TODO
void convert_ast(ast_node_t& ast, bool weak)
{
    switch(ast.token.type)
    {
    case TOK_ident:
        assert(ast.num_children() == 0);
        if(int const* handle = symbol_table.find(ast.token.pstring.view(source())))
        {
            ast.token.value = *handle;
            assert(ast.token.signed_() == *handle);
        }
        else
        {
            global_t& g = global_t::lookup(file.source(), ast.token.pstring);
            if(weak)
                weak_ideps.insert(&g);
            else
                ideps.insert(&g);
            ast.token.type = TOK_global_ident;
            ast.token.set_ptr(&g);
        }
        break;

    case TOK_at:
        assert(ast.num_children() == 1);
        convert_ast(ast.children[0], true);
        break;
        
    case TOK_period:
        assert(ast.num_children() == 1);
        convert_ast(ast.children[0], weak);
        break;

    case TOK_index:
        assert(ast.num_children() == 2);
        convert_weak(ast.children[0], weak);
        convert_ast(ast.children[1], false);
        break;

    case TOK_type_ident:
        {
            assert(ast.num_children() == 0);
            global_t& g = global_t::lookup(file.source(), ast.token.pstring);
            ideps.insert(&g);
            ast.token.set_ptr(&g);
        }
        break;

    case TOK_cast_type:
    case TOK_sizeof:
    case TOK_len:
        uses_type(*ast.token.ptr<type_t const>());
        // fall-through
    default:
        unsigned const n = ast.num_children();
        for(unsigned i = 0; i < n; ++i)
            convert_ast(ast.children[i], false);
    }
}
*/
