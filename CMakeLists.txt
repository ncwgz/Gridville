cmake_minimum_required(VERSION 3.16)
project(Gridville)

set(CMAKE_CXX_STANDARD 17)

include_directories(Google_tests/lib/include Google_tests/lib)

add_executable(Gridville main.cpp Gridville.cpp Gridville.h)

add_subdirectory(Google_tests)