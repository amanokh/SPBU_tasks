cmake_minimum_required(VERSION 3.16)
project(task9)

set(CMAKE_CXX_STANDARD 17)

add_executable(task9 main.cpp tree.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")