#pragma once

void run_add_rkey_test();
void run_xor_rkey_test();
void run_s_key_inv_test();

#define RUN_BASIC_TRANSFORMATIONS_TESTS run_xor_rkey_test(); \
                                        std::cerr << "===============================" << std::endl; \
                                        run_add_rkey_test(); \
                                        std::cerr << "===============================" << std::endl; \
                                        run_s_key_inv_test();
