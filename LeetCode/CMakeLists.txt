cmake_minimum_required(VERSION 3.10)
project(LeetCode)

add_compile_options("-Wno-c++11-extensions")
add_compile_options("-g")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)

add_executable(LeetCode1 LeetCode1.cpp)
