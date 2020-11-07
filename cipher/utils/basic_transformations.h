#pragma once

#include <cstdint>

void add_rkey(unsigned int*cipher_internal_state, unsigned int*key, size_t columns);
void xor_rkey(std::uint8_t *cipher_internal_state, std::uint8_t *key, size_t columns);

