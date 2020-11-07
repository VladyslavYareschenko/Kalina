#include "basic_transformations.h"

constexpr size_t internal_state_matrix_rows = 8;

int row = 8;

void add_rkey(unsigned int* dtn, unsigned int* src, size_t c) {
    unsigned int* dtn_res = new unsigned int[row];
    unsigned int* src_res = new unsigned int[row];

    for(int i = 0; i < c; i++) {
        for(int x = 0; x < row; x++) {
            dtn_res[x] = dtn[x + i * row];
            src_res[x] = src[x + i * row];
        }

        unsigned int val = 0;
        for(int x = 0; x < row; x++) {
            unsigned int gap = (dtn_res[x] + src_res[x] + val) >> 8;
            dtn_res[x] = (((dtn_res[x] + src_res[x] + val) >> 8) << 8) ^ (dtn_res[x] + src_res[x] + val);
            val = gap;
        }

        for(int x = 0; x < row; x++) { dtn[x + i * row] = dtn_res[x]; }
    }

    delete[] dtn_res;
    delete[] src_res;
}

//void add_rkey(unsigned int* cipher_internal_state, unsigned int*key, size_t columns)
//{
//    unsigned int* dtn_res = new unsigned int[internal_state_matrix_rows];
//        unsigned int* src_res = new unsigned int[internal_state_matrix_rows];

//        for(int i = 0; i < columns; i++) {
//            for(int x = 0; x < internal_state_matrix_rows; x++) {
//                dtn_res[x] = cipher_internal_state[x + i * internal_state_matrix_rows];
//                src_res[x] = key[x + i * internal_state_matrix_rows];
//            }

//            unsigned int val = 0;
//            for(int x = 0; x < internal_state_matrix_rows; x++) {
//                unsigned int gap = (dtn_res[x] + src_res[x] + val) >> 8;
//                dtn_res[x] = (((dtn_res[x] + src_res[x] + val) >> 8) << 8) ^ (dtn_res[x] + src_res[x] + val);
//                val = gap;
//            }

//            for(int x = 0; x < internal_state_matrix_rows; x++) { cipher_internal_state[x + i * internal_state_matrix_rows] = dtn_res[x]; }
//        }

//        delete[] dtn_res;
//        delete[] src_res;

////    cipher_internal_state[0] = cipher_internal_state[0] + key[0];
////    cipher_internal_state[1] = cipher_internal_state[1] + key[1];
//}

void xor_rkey(uint8_t *internal_state, uint8_t *key, size_t columns)
{
    for (size_t index = 0; index < columns * internal_state_matrix_rows; ++index)
    {
            internal_state[index] = internal_state[index] ^ key[index];
    }
}
