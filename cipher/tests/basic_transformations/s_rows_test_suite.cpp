#include "basic_transformations_tests.h"

#include "../test_utils.h"
#include "../../utils/basic_transformations.h"

#include <iostream>

unsigned __int64 M_s_row[10][2]={
{0x9A2B1EAC76EE891B,0x914ACF177C98DD3D},
{0x81D13FB27562EDE1,0xEA4B5542BFD1F76F},
{0x8FDA86338F6A9C7A,0xBEA63AB2ED4D5139},
{0x249A648F714775DF,0xE70E2C22E0FE9F0F},
{0xFA64888131B1FA10,0x4244C60765ED68AD},
{0xC5ED3FA44D7990FE,0x89EE6CDA99647C57},
{0x1DC39F955397E9F4,0x146C93B7F3486EE0},
{0x9AEC1045C38C3593,0xBBA1164CD70D8003},
{0x970380C8B39E909A,0x2C7CF1480055E5E5},
{0xFF661201789C581D,0x0374D34D5983C453}};

unsigned __int64 C_s_row[10][2]={
{0x9A2B1EAC7C98DD3D,0x914ACF1776EE891B},
{0x81D13FB2BFD1F76F,0xEA4B55427562EDE1},
{0x8FDA8633ED4D5139,0xBEA63AB28F6A9C7A},
{0x249A648FE0FE9F0F,0xE70E2C22714775DF},
{0xFA64888165ED68AD,0x4244C60731B1FA10},
{0xC5ED3FA499647C57,0x89EE6CDA4D7990FE},
{0x1DC39F95F3486EE0,0x146C93B75397E9F4},
{0x9AEC1045D70D8003,0xBBA1164CC38C3593},
{0x970380C80055E5E5,0x2C7CF148B39E909A},
{0xFF6612015983C453,0x0374D34D789C581D}};

void run_s_rows_test()
{
    constexpr size_t columns = 2;
    constexpr size_t rows = 8;
    constexpr size_t block_size = 64 * columns;


    bool failed = false;

    for (auto i = 0; i < 10; ++i)
    {
        s_row((uint8_t*)M_s_row[i], rows, columns, block_size);

        if (!compare_data_row(M_s_row[i], C_s_row[i], columns))
        {
            failed = true;
        }
    }

    if (failed)
    {
        std::cerr << "s_rows_test FAILED!" << std::endl;
    }
    else
    {
        std::cerr << "s_rows_test PASSED!" << std::endl;
    }
}
