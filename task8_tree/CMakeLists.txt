cmake_minimum_required(VERSION 3.15)
project(SPBUtasks2020)

set(CMAKE_CXX_STANDARD 17)

add_executable(SPBUtasks2020 task8.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")