cmake_minimum_required(VERSION 3.15)
project(task6)

set(CMAKE_CXX_STANDARD 17)

add_executable(task6 main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")