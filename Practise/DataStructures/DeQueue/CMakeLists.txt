cmake_minimum_required(VERSION 3.20)
project(dequeue VERSION 1.0
                LANGUAGES CXX)


# Options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Build
add_executable(appDequeue src/DeQueue.hpp 
                          src/DeQueue.txx 
                          src/main.cpp)
