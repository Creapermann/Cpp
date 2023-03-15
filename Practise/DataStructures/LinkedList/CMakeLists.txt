cmake_minimum_required(VERSION 3.20)
project(linkedList VERSION 1.0
                   LANGUAGES CXX)


# Options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})



# Dependencies
add_subdirectory(tests)



# Build
add_executable(app src/LinkedList.hpp src/LinkedList.txx src/main.cpp)
