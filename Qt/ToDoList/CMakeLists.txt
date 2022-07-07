cmake_minimum_required(VERSION 3.20)


project(ToDoList VERSION 0.1 LANGUAGES CXX)



# Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Language
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)



# Dependencies
find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)



# Build
qt_add_executable(apptesting
    main.cpp
    todo_list.hpp
    todo_list_model.cpp
    todo_list.hpp
    todo_list.cpp
    qmlSources.qrc
)


set_target_properties(apptesting PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(apptesting
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(apptesting
    PRIVATE Qt6::Quick)




# Qml-Module
qt6_add_qml_module(apptesting
  URI "Testing.QmlComponents"
  VERSION 1.0
)