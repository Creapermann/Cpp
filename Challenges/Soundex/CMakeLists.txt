cmake_minimum_required(VERSION 3.18)

project(MyApp VERSION 1.0.0)

enable_testing()

#build
set(CMAKE_BUILD_TYPE Debug)

# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)


# options
option(BUILD_TESTS ON)



# Add libraries
add_subdirectory(src/soundex/)


# Build project
add_executable(app
                src/app/main.cpp
    )

target_link_libraries(app
            PRIVATE
                soundex
    )

target_include_directories(app
            PRIVATE
                src/app/
    )



# Tests
if(BUILD_TESTS)
    add_subdirectory(lib/googletest)
    add_subdirectory(tests/)
endif()