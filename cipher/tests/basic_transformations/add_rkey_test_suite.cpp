#include "basic_transformations_tests.h"

#include "../test_utils.h"
#include "../../utils/basic_transformations.h"

#include <iostream>

namespace
{
std::uint64_t M_add_rkey[4][2]={
{0x1011121314151617,0x18191A1B1C1D1E1F},
{0x2A996BD4E2BFE707,0xEBBDF763CBFA64A5},
{0x2021222324252627,0x28292A2B2C2D2E2F},
{0x95CD566091D32765,0xB72653E17180F381}};

std::uint64_t RK_add_rkey[4][2]={
{0x16505E6B9B3AB1E6,0x865B77DCE082A0F4},
{0xB8AA879A2086A66D,0xD80A9872E25CD2B0},
{0x57C816EB3F7E12DE,0xED2C6B56E6B5BE1A},
{0x2BBFF92FF9794546,0xB343FADB28A0D1D4}};

std::uint64_t C_add_rkey[4][2]={
{0x2661707EAF4FC7FD,0x9E7491F7FC9FBE13},
{0x81BF1C7D779BAC20,0xE1C9EA39B4D2AD06},
{0x77E9380E64A33805,0x1556958112E3EC49},
{0x58EC3E091000158A,0x1148F7166F334F14}};
}

void run_add_rkey_test()
{
    constexpr size_t columns = 2;

    bool failed = false;

    for (auto i = 0; i < 4; ++i)
    {
        add_rkey(M_add_rkey[i], RK_add_rkey[i], columns);

        if (!compare_data_row(M_add_rkey[i], C_add_rkey[i], columns))
        {
            failed = true;
        }
    }

    if (failed)
    {
        std::cerr << "add_rkey_test FAILED!" << std::endl;
    }
    else
    {
        std::cerr << "add_rkey_test PASSED!" << std::endl;
    }
}
