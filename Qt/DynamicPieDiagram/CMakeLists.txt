cmake_minimum_required(VERSION 3.20)

project(DynamicPieDiagram VERSION 0.1 LANGUAGES CXX)



# Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



# Language
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)



# Build
qt_add_executable(appDynamicPieDiagram
    main.cpp
    PieChart.cpp
    PieChart.hpp
    sources.qrc
)

set_target_properties(appDynamicPieDiagram
                PROPERTIES
                    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
                    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
                    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
                    MACOSX_BUNDLE TRUE
                    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appDynamicPieDiagram
                PRIVATE
                    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)
target_link_libraries(appDynamicPieDiagram
                PRIVATE
                    Qt6::Quick
)



# Module
qt_add_qml_module(appDynamicPieDiagram
    URI DynamicPieDiagram.Elements
    VERSION 1.0
)