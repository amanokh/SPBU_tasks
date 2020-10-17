cmake_minimum_required(VERSION 3.17)
project(task3_2d_iter)

set(CMAKE_CXX_STANDARD 17)

add_executable(task3_2d_iter main.cpp tests/basic_tests/basic_check.cpp)

add_subdirectory(tests)