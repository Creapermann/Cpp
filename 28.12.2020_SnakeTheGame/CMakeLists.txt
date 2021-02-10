cmake_minimum_required(VERSION 3.0)

project(Snake)

add_subdirectory(extern)

set(CMAKE_CXX_STANDARD 17)

set(libPath ${CMAKE_CURRENT_SOURCE_DIR}/extern)

include_directories(${libPath}/conio)
link_directories(${libPath}/conio)

add_executable(
  Snake

  src/main.cpp
)


target_link_libraries(${PROJECT_NAME} PUBLIC conio)
