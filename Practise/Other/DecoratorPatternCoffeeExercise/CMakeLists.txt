cmake_minimum_required(VERSION 3.22)
project(DecoratorPatternCoffeeExercise)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DecoratorPatternCoffeeExercise
               main.cpp
               Beverage.cpp
               Beverage.hpp
               Espresso.cpp
               Espresso.hpp
               HouseBlend.cpp
               HouseBlend.hpp
               BeverageDecorator.hpp
               Latte.cpp
               Latte.hpp Decaff.cpp Decaff.hpp)
