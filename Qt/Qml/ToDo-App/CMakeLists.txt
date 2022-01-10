cmake_minimum_required(VERSION 3.19)

project(ToDo 
            VERSION 0.1 
            LANGUAGES CXX)

# Qt
list(APPEND CMAKE_PREFIX_PATH "/home/creapermann/Qt/6.2.2/gcc_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Options
option(BUILD_TESTS ON)





# Deps
find_package(Qt6 6.2 COMPONENTS Quick QuickControls2  REQUIRED)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG 6b74da4757a549563d7c37c8fae3e704662a043b
    )

FetchContent_MakeAvailable(googletest)




# Sources
list(APPEND model_src
    )

list(APPEND controller_src
    )


# Building the app
add_executable(appDashboard
                        src/app/main.cpp
                        resources/resources.qrc
                        
                        ${model_src}
                        ${controller_src}
    )

qt_add_qml_module(appDashboard
    URI Dashboard
    VERSION 1.0
    QML_FILES 
        src/app/view/main.qml
        src/app/view/MSidebar.qml
    )

target_compile_definitions(appDashboard
                    PRIVATE 
                        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
    )

target_link_libraries(appDashboard
                    PRIVATE 
                        Qt6::Quick
    )




# tests
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()