#pragma once

void run_add_rkey_test();
void run_xor_rkey_test();
void run_s_key_inv_test();
void run_s_box_test();
void run_s_rows_test();
void run_m_col_test();

#define RUN_BASIC_TRANSFORMATIONS_TESTS run_xor_rkey_test(); \
                                        std::cerr << "===============================" << std::endl; \
                                        run_add_rkey_test(); \
                                        std::cerr << "===============================" << std::endl; \
                                        run_s_key_inv_test(); \
                                        std::cerr << "===============================" << std::endl; \
                                        run_s_box_test();     \
                                        std::cerr << "===============================" << std::endl; \
                                        run_s_rows_test();    \
                                        std::cerr << "===============================" << std::endl; \
                                        run_m_col_test();
