cmake_minimum_required(VERSION 3.16)
project(Google_tests)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
include_directories(./lib/include ../)

add_executable(Gridville_gtest test.cpp ../Gridville.cpp)
target_link_libraries(Gridville_gtest gtest gtest_main)