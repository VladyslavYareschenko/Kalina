#include "basic_transformations.h"

#include <cassert>
#include <limits>

#include <iostream>

constexpr size_t internal_state_matrix_rows = 8;

namespace calculation_primitives
{
uint8_t mul_pol(uint8_t a, uint8_t b)
{
    constexpr uint16_t mod = 0x011d;  /* x^8 + x^4 + x^3 + x^2 + 1 */

    uint32_t new_b = b;
    uint8_t res = 0;

    while (a)
    {
        if (a & 1)
        {
            res ^= new_b;
        }

        new_b <<= 1;

        if (new_b > 0xff)
        {
            new_b ^= mod;
        }

        a >>= 1;
    }

    return res;
}

void shift_row(uint8_t* row, size_t row_length, size_t shift)
{
    uint8_t tmp[shift];
    memcpy(tmp, row + row_length - shift, shift * sizeof(uint8_t));

    memcpy(row + shift, row, (row_length - shift) * sizeof(uint8_t));
    memcpy(row, tmp, shift * sizeof(uint8_t));
}

void fill_v_matrix(uint8_t *v_string, uint8_t *v_matrix)
{
    memcpy(&v_matrix[0], v_string, 8 * sizeof(uint8_t));

    uint8_t indexes_to_shift[8];
    memcpy(indexes_to_shift, v_matrix, 8 * sizeof(uint8_t));

    for (size_t i = 1; i < 8; ++i)
    {
        shift_row(indexes_to_shift, 8, 1);
        memcpy(&v_matrix[i * 8], indexes_to_shift, 8 * sizeof(uint8_t));
    }
}
} // namespace calculation_primitives

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

void s_box(uint8_t *block, uint8_t *substitution, size_t rows, size_t columns)
{
    assert(rows <= (std::numeric_limits<uint8_t>::max() + 1) &&
           columns <= (std::numeric_limits<uint8_t>::max() + 1));

    for (size_t i = 0; i < rows * columns; i++)
    {
        block[i] = substitution[(i % 4) * 256 + block[i]];
    }
}

void s_row(uint8_t *source, size_t rows, size_t columns, size_t cipher_block_size)
{
    for (size_t row = 0; row < rows; ++row)
    {
        size_t shift = row * cipher_block_size / 512;

        if (shift > 0 && shift % columns != 0)
        {
            uint8_t shifted_row[columns];
            for(size_t i = 0; i < columns; i++)
            {
                // Due to Big-endian. TODO: Support Little-endian
                shifted_row[i] = source[rows - row - 1 + i * rows];
            }

            calculation_primitives::shift_row(shifted_row, columns, shift);

            for(size_t i = 0; i < columns; i++)
            {
                source[rows - row - 1 + i * rows] = shifted_row[i];
            }
        }
    }
}

void m_col(uint8_t *v_string, uint8_t *input, uint8_t *output, size_t rows, size_t columns)
{
    uint8_t v_matrix[8][8];

    calculation_primitives::fill_v_matrix(v_string, &v_matrix[0][0]);

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            output[i + j * rows] = 0;

            for (size_t k = 0; k < rows; ++k)
            {
                const uint8_t res = calculation_primitives::mul_pol(v_matrix[i][k], input[j * rows + k]);
                output[i + j * rows] ^= res;
            }
        }
    }
}
