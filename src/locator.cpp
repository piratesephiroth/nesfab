#include "locator.hpp"

#include "format.hpp"
#include "globals.hpp"
#include "type.hpp"
#include "ir.hpp"

std::string to_string(locator_t loc)
{
    std::string str;

    switch(loc.lclass())
    {
    default: 
        return "unknown locator";
    case LOC_NONE:
        return "none";
    case LOC_IOTA:
        str = "offset"; break;
    case LOC_GMEMBER:
        str = fmt("gmember %", loc.gmember()->gvar.global.name); break;
    case LOC_GMEMBER_SET:
        str = fmt("gset %", loc.handle()); break;
    case LOC_GLOBAL_CONST:
        str = fmt("global const %", loc.const_()->global.name); break;
    case LOC_FN:
        str = fmt("fn %", loc.fn()->global.name); break;
    case LOC_ARG:
        str = fmt("arg %", loc.fn()->global.name); break;
    case LOC_RETURN:
        str = fmt("ret %", loc.fn()->global.name); break;
    case LOC_PHI:
        str = fmt("phi %", loc.fn()->global.name); break;
    case LOC_CFG_LABEL:
        str = fmt("cfg label %", loc.fn()->global.name); break;
    case LOC_MINOR_LABEL:
        str = fmt("minor label %", loc.fn()->global.name); break;
    case LOC_CONST_BYTE:
        str = "const byte"; break;
    case LOC_SSA:
        str = fmt("ssa %", loc.handle()); break;
    case LOC_MINOR_VAR:
        str = fmt("minor var %", loc.fn()->global.name); break;
    case LOC_ROM_ARRAY:
        str = "rom_array"; break;
    }

    if(has_arg_member_atom(loc.lclass()))
        str += fmt(" %.%:% (%)", (int)loc.arg(), (int)loc.member(), (int)loc.atom(), (int)loc.offset());
    else
        str += fmt(" [%] (%)", (int)loc.data(), (int)loc.offset());

    return str;
}

std::ostream& operator<<(std::ostream& o, locator_t loc)
{
    o << to_string(loc);
    return o;
}

locator_t locator_t::from_ssa_value(ssa_value_t v)
{
    if(v.holds_ref())
        return ssa(v.handle());
    else if(v.is_num())
        return const_byte(v.whole());
    else if(v.is_locator())
        return v.locator();
    else
        return none();
}

type_t locator_t::mem_type() const
{
    switch(lclass())
    {
    case LOC_IOTA:
        return type_t::array(TYPE_U, 256);
    case LOC_GMEMBER: 
        return gmember()->type();
    case LOC_ARG:
        return fn()->type().type(arg());
    case LOC_RETURN:
        return fn()->type().return_type();
    case LOC_CONST_BYTE:
        return TYPE_U;
    case LOC_SSA:
        assert(compiler_phase() == PHASE_COMPILE);
        return ssa_node()->type();
    default:
        return TYPE_VOID;
    }
}

std::size_t locator_t::mem_size() const
{
    type_t const t = mem_type();

    switch(t.name())
    {
    case TYPE_ARRAY: 
        return t.size();
    case TYPE_PTR:
    case TYPE_BANKED_PTR:
        return atom() == 0 ? 2 : 1;
    default:
        assert(!is_ptr(t.name()));
        return 1;
    }
}

bool locator_t::mem_zp_only() const
{
    type_t const t = mem_type();
    return is_ptr(t.name()) && atom() == 0;
}
