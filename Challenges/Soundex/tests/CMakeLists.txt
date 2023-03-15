cmake_minimum_required(VERSION 3.18)



# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)




# Build tests
add_executable(all_tests
                    main.cpp
                    Soundex_Test.hpp
    )

target_link_libraries(all_tests
                PRIVATE
                    gtest
                    soundex
    )


# Run tests at build-time
add_custom_target(run_tests ALL
            COMMAND all_tests
    )