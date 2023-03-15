cmake_minimum_required(VERSION 3.20)
project(StdUnexpectedImpl VERSION 1.0
                          LANGUAGES CXX)
                      

# Language
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Build
add_executable(expected main.cpp expected.hpp unexpected.hpp details.hpp)

target_compile_options(expected PRIVATE "-Og;-Wall;-Wextra")
