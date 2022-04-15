cmake_minimum_required(VERSION 3.22)
project(searchInsertPosition VERSION 1.0
                             LANGUAGES CXX
)


# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# Build
add_executable(app
                    main.cpp
)