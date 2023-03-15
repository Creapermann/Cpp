cmake_minimum_required(VERSION 3.20)
project(stack VERSION 1.0
                   LANGUAGES CXX)


# Options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Build
add_library(appStack SHARED 
                        src/Stack.hpp 
                        src/Stack.txx)
