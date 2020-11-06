cmake_minimum_required(VERSION 2.8)

project(Kalina)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "cipher/utils/basic_transformations.h"
    "cipher/utils/basic_transformations.cpp")
