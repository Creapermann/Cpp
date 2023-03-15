#pragma once
#include <type_traits>

namespace my_std
{

template<typename T>
concept Copyable = std::is_copy_constructible<T>::value;

template<typename T>
concept DefaultConstructable = std::is_default_constructible<T>::value;

}