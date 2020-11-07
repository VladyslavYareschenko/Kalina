#include "basic_transformations.h"

#include <cassert>
#include <limits>

#include <iostream>

constexpr size_t internal_state_matrix_rows = 8;

void add_rkey(uint64_t* internal_state, uint64_t *key, size_t columns)
{
    for (size_t index = 0; index < columns; ++index)
    {
        internal_state[index] = internal_state[index] + key[index];
    }
}

void xor_rkey(uint64_t *internal_state, uint64_t *key, size_t columns)
{
    for (size_t index = 0; index < columns; ++index)
    {
        internal_state[index] = internal_state[index] ^ key[index];
    }
}

void s_key_inv(uint8_t *key, uint8_t *inv_key, size_t rows, size_t columns)
{
    assert(rows <= (std::numeric_limits<uint8_t>::max() + 1) &&
           columns <= (std::numeric_limits<uint8_t>::max() + 1));

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            inv_key[i * columns + key[i  * columns + j]] = j;
        }
    }
}
