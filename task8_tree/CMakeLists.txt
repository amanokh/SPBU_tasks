cmake_minimum_required(VERSION 3.15)
project(task8)

set(CMAKE_CXX_STANDARD 17)

add_executable(task8 main.cpp tree.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")