cmake_minimum_required(VERSION 3.17)
project(task4)

set(CMAKE_CXX_STANDARD 17)

add_executable(task4 main.cpp tests/basic_tests/basic_check.cpp)

add_subdirectory(tests)