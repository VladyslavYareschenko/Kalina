#include "test_utils.h"

#include <iostream>
#include <memory.h>

void print_row(const uint64_t *begin, size_t size)
{
    std::cerr << std::hex << std::uppercase;

    for (size_t i = 0; i < size; ++i)
    {
        std::cerr << begin[i];
    }

    std::cerr << std::dec << std::nouppercase;
}

bool compare_data_row(const uint64_t *actual, const uint64_t *expected, size_t columns)
{
    if (memcmp(actual, expected, sizeof(uint64_t) * columns))
    {
        std::cerr << "Comparison failed! Data: " << std::endl;

        std::cerr << "Actual:   ";
                     print_row(actual, columns);
        std::cerr << std::endl;

        std::cerr << "Expected: ";
                   print_row(expected, columns);
        std::cerr << std::endl;

        return false;
    }

    return true;
}
