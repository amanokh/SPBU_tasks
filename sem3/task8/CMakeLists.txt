cmake_minimum_required(VERSION 3.17)
project(task8)

set(CMAKE_CXX_STANDARD 17)

add_executable(task8 main.cpp polynom.cpp polynom.h)

add_subdirectory(tests)