cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(quickSort)

add_executable(
    quickSort

    quickSort.cpp
    quickSort.hpp
)
