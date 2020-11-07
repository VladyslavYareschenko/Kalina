#pragma once

#include <cstdint>

void add_rkey(uint64_t *internal_state, uint64_t *key, size_t columns);
void xor_rkey(uint64_t *internal_state, uint64_t *key, size_t columns);
void s_key_inv(uint8_t *key, uint8_t *inv_key, size_t rows, size_t columns);
