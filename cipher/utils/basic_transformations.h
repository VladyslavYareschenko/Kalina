#pragma once

#include <cstdint>

void s_key_inv(uint8_t *key, uint8_t *inv_key, size_t rows, size_t columns);

void s_box(uint8_t *block, uint8_t *substitution, size_t rows, size_t columns);

void s_row(uint8_t *source, size_t rows, size_t colums, size_t cipher_block_size);

void add_rkey(uint64_t *internal_state, uint64_t *key, size_t columns);

void xor_rkey(uint64_t *internal_state, uint64_t *key, size_t columns);

void m_col(uint8_t *v_string, uint8_t *input, uint8_t *output, size_t rows, size_t columns);
