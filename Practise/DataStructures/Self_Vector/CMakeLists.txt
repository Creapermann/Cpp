cmake_minimum_required(VERSION 3.20)
project(selfVector VERSION 1.0
                   LANGUAGES CXX)


# Options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Build
add_executable(appSelfVector src/SelfVector.hpp 
                             src/SelfVector.txx 
                             src/main.cpp)
