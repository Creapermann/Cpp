cmake_minimum_required(VERSION 3.20)

project(AttachedListener VERSION 0.1 LANGUAGES CXX)



# Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



# Language
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# Dependencies
find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)



# Build
qt_add_executable(appAttachedListener
    main.cpp
    Attachee.cpp
    Attachee.hpp
    Attacher.cpp
    Attacher.hpp
    AttatchedListener.cpp
    AttatchedListener.hpp
    sources.qrc
)

set_target_properties(appAttachedListener PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appAttachedListener
                PRIVATE
                    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)
target_link_libraries(appAttachedListener
                PRIVATE
                    Qt6::Quick
)



# Modules
qt6_add_qml_module(appAttachedListener
    URI AttachedListener
    VERSION 1.0
)