cmake_minimum_required(VERSION 3.14)
project(AcWing)

set(CMAKE_CXX_STANDARD 14)

add_executable(test test.cpp)

add_subdirectory(AcWing)
add_subdirectory(LuoGu)
add_subdirectory(LeetCode)