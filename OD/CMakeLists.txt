cmake_minimum_required(VERSION 3.10)
project(OD)

# 忽略特定的警告
add_compile_options("-Wno-c++11-extensions")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)

# add_executable(OD1 OD1.cpp)
# add_executable(OD2 OD2.cpp)
# add_executable(OD3 OD3.cpp)
add_executable(OD4 OD4.cpp)
