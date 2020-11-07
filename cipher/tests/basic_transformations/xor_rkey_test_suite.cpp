#include "basic_transformations_tests.h"
#include "../../utils/basic_transformations.h"

#include <iostream>
#include <mem.h>

namespace
{
std::uint64_t M_xor_rkey[9][2]={
{0x16CEDEE8D9990F9E,0x25B506F042D3B305},
{0x32F172C7E2D2E1C9,0x3B4D13958FBCE28D},
{0x044E672502E945D3,0x13F24197773D4547},
{0x73EC521DA9BAF977,0x7A44212456FE0215},
{0x5DCBF7EE9765340D,0x700AB86C7E3CFCBC},
{0x9EDCE2CB1E774F27,0x2D2C66281402B14F},
{0x44B90F555C682F06,0x8FDB6918B7108ED5},
{0x1073FCB6ECF68F31,0xBCB77E752220169C},
{0x375DCC2C800C45F6,0x1DD9C471E522E0A6}};

std::uint64_t RK_xor_rkey[9][2]={
{0xE6865B77DCE082A0,0xF416505E6B9B3AB1},
{0x7E70876EAE498476,0x8AAAA00A7C93EC42},
{0x768AAAA00A7C93EC,0x427E70876EAE4984},
{0x45CED4C51E9140F5,0x3E7276820F0BD9FE},
{0xF53E7276820F0BD9,0xFE45CED4C51E9140},
{0xFE45CED4C51E9140,0x515F66320560C4B1},
{0x62515F66320560C4,0xB18C77EE227900C4},
{0x0A9872E25CD2B0B8,0xAA879A2086A66DD8},
{0xB8AA879A2086A66D,0xD80A9872E25CD2B0}};

std::uint64_t C_xor_rkey[9][2]={
{0xF048859F05798D3E,0xD1A356AE294889B4},
{0x4C81F5A94C9B65BF,0xB1E7B39FF32F0ECF},
{0x72C4CD850895D63F,0x518C311019930CC3},
{0x362286D8B72BB982,0x443657A659F5DBEB},
{0xA8F58598156A3FD4,0x8E4F76B8BB226DFC},
{0x12AB0CE967778B45,0x7C73001A116275FE},
{0x26E850336E6D4FC2,0x3E571EF695698E11},
{0x1AEB8E54B0243F89,0x1630E455A4867B44},
{0x8FF74BB6A08AE39B,0xC5D35C03077E3216}};

}

void run_xor_rkey_test()
{
    std::cerr << "xor_key_test STARTED!" << std::endl;

    constexpr size_t columns = 2;
    constexpr size_t block_size = sizeof(std::uint64_t) * columns;

    auto* matrix_begin = (std::uint8_t*)M_xor_rkey[0];
    auto* key_begin = (std::uint8_t*)RK_xor_rkey[0];

    bool failed = false;

    for (auto i = 0; i < 9; ++i)
    {
        xor_rkey(matrix_begin, key_begin, 2u);

        if (memcmp(M_xor_rkey[i], C_xor_rkey[i], block_size))
        {
            failed = true;

            std::cerr << "Comparison failed! Data row number: " << i + 1 << std::endl;
        }
        else
        {
            std::cerr << "Comparison succeed! Data row number: " << i + 1 << std::endl;
        }

        matrix_begin += block_size;
        key_begin += block_size;
    }

    if (failed)
    {
        std::cerr << "xor_key_test FAILED!" << std::endl;
    }
    else
    {
        std::cerr << "xor_key_test PASSED!" << std::endl;
    }
}
