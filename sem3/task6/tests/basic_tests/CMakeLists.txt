include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../lib/googletest/include ../lib/googletest)
add_executable(runBasicTests basic_check.cpp)
target_link_libraries(runBasicTests gtest gtest_main)