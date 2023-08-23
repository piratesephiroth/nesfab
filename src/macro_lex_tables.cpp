#include "macro_lex_tables.hpp"
namespace macro_lex
{
extern unsigned const lexer_ec_table[256] = {
    0, 61, 61, 61, 61, 61, 61, 61, 61, 61, 122, 61, 61, 183, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 244, 305, 61, 61, 61, 366, 61, 61, 427, 61, 61, 488, 61, 549,
    610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 671, 61, 61, 732, 61, 61,
    61, 793, 793, 793, 793, 793, 793, 793, 793, 793, 793, 793, 793, 793, 793, 793,
    793, 793, 793, 793, 793, 793, 793, 793, 793, 793, 793, 61, 61, 61, 61, 610,
    854, 915, 915, 915, 915, 915, 915, 915, 915, 915, 915, 915, 915, 915, 915, 915,
    915, 915, 915, 915, 915, 915, 915, 915, 915, 915, 915, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
    61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
};
extern token_type_t const lexer_transition_table[976] = {

    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 18, 34, 0, 5, 0, 0, 21, 0, 0, 0, 0, 0, 0, 5,
    7, 5, 1, 3, 0, 4, 0, 2, 0, 10, 0, 0, 12, 0, 0, 13,
    0, 0, 0, 11, 0, 0, 0, 9, 0, 0, 8, 18, 6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18,
    0, 0, 5, 0, 0, 24, 0, 0, 0, 0, 0, 0, 5, 7, 5, 1,
    3, 0, 4, 0, 2, 0, 10, 0, 0, 12, 0, 0, 13, 0, 0, 0,
    11, 0, 0, 0, 9, 0, 0, 8, 18, 6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 5,
    0, 0, 33, 0, 0, 0, 0, 0, 0, 21, 7, 5, 1, 3, 0, 4,
    0, 2, 0, 10, 0, 0, 12, 0, 0, 13, 0, 0, 0, 11, 0, 0,
    0, 9, 0, 0, 8, 18, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 5, 0, 0, 31,
    0, 0, 0, 0, 0, 0, 5, 7, 21, 1, 3, 0, 4, 0, 2, 0,
    10, 0, 0, 12, 0, 0, 13, 0, 0, 0, 11, 0, 0, 0, 9, 0,
    0, 8, 18, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 57, 0, 18, 35, 0, 5, 0, 0, 24, 0, 0, 0,
    0, 0, 0, 5, 7, 5, 1, 3, 22, 4, 0, 2, 0, 10, 0, 0,
    12, 0, 0, 13, 0, 0, 0, 11, 0, 0, 0, 9, 57, 0, 8, 18,
    6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 32, 18, 36, 32, 5, 0, 0, 24, 0, 0, 0, 0, 0, 0,
    5, 7, 5, 1, 3, 0, 4, 0, 2, 41, 10, 0, 44, 12, 0, 47,
    13, 0, 0, 51, 11, 0, 0, 55, 9, 0, 58, 8, 18, 6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    18, 37, 0, 5, 0, 0, 24, 0, 0, 0, 0, 0, 0, 5, 7, 5,
    1, 3, 26, 4, 0, 2, 0, 10, 0, 0, 12, 0, 0, 13, 0, 0,
    0, 11, 54, 54, 0, 9, 0, 0, 8, 18, 6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59, 0, 0,
    5, 0, 0, 24, 0, 0, 0, 0, 0, 0, 5, 7, 5, 1, 3, 0,
    4, 18, 2, 0, 10, 0, 0, 12, 0, 0, 13, 0, 0, 0, 11, 0,
    0, 0, 9, 0, 0, 8, 18, 6, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 5, 0, 0,
    24, 0, 0, 0, 0, 0, 0, 5, 7, 5, 1, 3, 27, 4, 0, 2,
    0, 10, 0, 0, 12, 0, 0, 13, 50, 50, 0, 11, 0, 0, 0, 9,
    0, 0, 8, 18, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 18, 38, 0, 5, 0, 0, 24, 0, 0,
    0, 0, 0, 0, 5, 7, 5, 1, 3, 0, 4, 24, 2, 0, 10, 0,
    0, 12, 0, 0, 13, 0, 0, 0, 11, 0, 0, 0, 9, 0, 0, 8,
    60, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    14, 15, 16, 17, 18, 0, 20, 5, 0, 23, 24, 25, 0, 0, 0, 0,
    0, 5, 7, 5, 1, 3, 0, 4, 0, 2, 0, 10, 42, 0, 12, 45,
    0, 13, 48, 49, 0, 11, 52, 53, 0, 9, 56, 0, 8, 18, 6, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 18, 0, 0, 5, 0, 46, 24, 0, 0, 0, 0, 0, 0, 5, 7,
    5, 1, 3, 28, 4, 0, 2, 0, 10, 0, 0, 12, 46, 0, 13, 0,
    0, 0, 11, 0, 0, 0, 9, 0, 0, 8, 18, 6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0,
    0, 5, 0, 0, 24, 43, 0, 0, 0, 0, 0, 5, 7, 5, 1, 3,
    29, 4, 0, 2, 0, 10, 43, 0, 12, 0, 0, 13, 0, 0, 0, 11,
    0, 0, 0, 9, 0, 0, 8, 18, 6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 14, 0, 16, 0, 18, 0, 20, 5, 16,
    23, 24, 0, 52, 48, 23, 42, 14, 5, 7, 5, 1, 3, 20, 4, 0,
    2, 0, 10, 42, 0, 12, 0, 0, 13, 48, 0, 0, 11, 52, 0, 0,
    9, 0, 0, 8, 18, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 40, 40, 0, 0, 18, 39, 0, 5, 0, 0, 24, 0,
    0, 0, 0, 0, 0, 5, 7, 5, 1, 3, 30, 4, 0, 2, 0, 10,
    0, 0, 12, 0, 0, 13, 0, 0, 0, 11, 0, 0, 0, 9, 0, 0,
    8, 18, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 15, 0, 17, 18, 0, 0, 5, 56, 0, 24, 25, 53, 49, 45,
    25, 15, 5, 7, 5, 1, 3, 17, 4, 0, 2, 0, 10, 0, 0, 12,
    45, 0, 13, 0, 49, 0, 11, 0, 53, 0, 9, 56, 0, 8, 18, 6,
};
} // namespace macro_lex
