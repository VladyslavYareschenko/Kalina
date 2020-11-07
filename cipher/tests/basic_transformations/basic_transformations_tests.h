#pragma once

void run_add_rkey_test();
void run_xor_rkey_test();

#define RUN_BASIC_TRANSFORMATIONS_TESTS /*run_xor_rkey_test();*/ \
                                        run_add_rkey_test();
