cmake_minimum_required(VERSION 3.18)

project(Soundex VERSION 1.0.0)


add_library(soundex SHARED
                Soundex.cpp
                Soundex.hpp
    )

target_include_directories(soundex
                PUBLIC
                    ${PROJECT_SOURCE_DIR}/
                    ${PROJECT_BINARY_DIR}/
    )


include(GenerateExportHeader)
generate_export_header(soundex)