cmake_minimum_required(VERSION 3.20)


# Options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Fetch googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)


# Build
add_executable(linked_list_tests main.cpp linked_list_tests.cpp)
target_link_libraries(linked_list_tests gtest)
target_include_directories(linked_list_tests PRIVATE ${PROJECT_SOURCE_DIR}/src)
