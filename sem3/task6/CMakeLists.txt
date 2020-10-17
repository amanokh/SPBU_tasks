cmake_minimum_required(VERSION 3.17)
project(task6)

set(CMAKE_CXX_STANDARD 17)

add_executable(task6 main3.cpp tests/basic_tests/basic_check.cpp)

add_subdirectory(tests)