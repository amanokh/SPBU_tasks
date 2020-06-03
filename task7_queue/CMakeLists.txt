cmake_minimum_required(VERSION 3.16)
project(task7)

set(CMAKE_CXX_STANDARD 17)

add_executable(task7 main.cpp queue.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")