cmake_minimum_required(VERSION 2.8)

project(Kalina)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "cipher/utils/basic_transformations.h"
    "cipher/utils/basic_transformations.cpp"
    "cipher/tests/basic_transformations/basic_transformations_tests.h"
    "cipher/tests/test_utils.h"
    "cipher/tests/test_utils.cpp"
    "cipher/tests/basic_transformations/xor_rkey_test_suite.cpp"
    "cipher/tests/basic_transformations/add_rkey_test_suite.cpp"
    "cipher/tests/basic_transformations/s_key_inv_test_suite.cpp"
    "cipher/tests/basic_transformations/s_box_test_suite.cpp"
    "cipher/tests/basic_transformations/s_rows_test_suite.cpp"
    "cipher/tests/basic_transformations/m_col_test_suite.cpp")

