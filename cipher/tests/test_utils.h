#pragma once

#include <stddef.h>
#include <cstdint>

bool compare_data_row(const uint64_t *actual, const uint64_t *expected, size_t columns);
