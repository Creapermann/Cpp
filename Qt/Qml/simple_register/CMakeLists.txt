cmake_minimum_required(VERSION 3.19)

project(Learning VERSION 0.1 
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



# Deps
find_package(Qt6 6.2 COMPONENTS Quick QuickControls2 REQUIRED)



# Building executable
add_executable(appLearning
    src/app/main.cpp
    resources/resources.qrc
)

qt_add_qml_module(appLearning
    URI Learning
    VERSION 1.0
    QML_FILES 
        src/app/view/main.qml
        src/app/view/components/MButton.qml
)

target_compile_definitions(appLearning
                    PRIVATE 
                        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
    )

target_link_libraries(appLearning
                    PRIVATE
                        Qt6::Quick
                        Qt6::QuickControls2
    )