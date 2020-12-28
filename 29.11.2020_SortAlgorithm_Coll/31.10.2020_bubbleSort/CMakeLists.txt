cmake_minimum_required(VERSION 3.5)

project(BubbleSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(mylib_path "/usr/local/pkg/")
set(mytest_path "${CMAKE_CURRENT_SOURCE_DIR}/tests")

add_subdirectory(tests)
add_subdirectory(src)

include_directories(${mylib_path}/compiled/gtest/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_executable(
  ${CMAKE_PROJECT_NAME}

  src/main.cpp
  src/bubbleSort.cpp

  #tests
  ${mytest_path}/test1/maintest.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} libgtest.a)
