cmake_minimum_required(VERSION 3.16)
project(task1_graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(task1_graph main.cpp utils.h graph.cpp graph.h)
target_link_libraries(task1_graph openbgi gdi32 opengl32 freeglut glu32)