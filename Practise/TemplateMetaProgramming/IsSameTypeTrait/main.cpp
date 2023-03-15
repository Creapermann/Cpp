#include <iostream>
#include <memory>
#include <string>
#include <cxxabi.h>


// Remove_CV type trait
template<typename T>
struct type_identity
{
    using type = T;
};



template<typename T>
struct remove_const : type_identity<T> {};


template<typename T>
struct remove_const<T const> : type_identity<T> {};


template<typename T>
struct remove_volatile : type_identity<T> {};

template<typename T>
struct remove_volatile<T volatile> : type_identity<T> {};


template<typename T>
using remove_cv = remove_volatile<typename remove_const<T>::type>;

template<typename T>
using remove_cv_t = typename remove_cv<T>::type;



// Is_Same type trait
template<typename T, T val>
struct integral_constant
{
    static constexpr T value = val;

    using value_type = T;
    using type = integral_constant<T, val>;

    constexpr operator value_type()
    {
        return value;
    }

    constexpr value_type operator()()
    {
        return value;
    }
};


template<bool val>
using bool_constant = integral_constant<bool, val>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;


template<typename T, typename U>
struct is_same : false_type {};

template<typename T>
struct is_same<T, T> : true_type {};



template<typename T, typename U>
constexpr bool is_same_v = is_same<remove_cv_t<T>, remove_cv_t<U>>::value;




int main()
{
    // Test the type trait
    static_assert(not is_same_v<int, double>, "int & double");
    static_assert(not is_same_v<float, double>, "float & double");
    static_assert(not is_same_v<const char, volatile int>, "const char & volatile int");
    
    static_assert(is_same_v<char, char>, "char & char");
    static_assert(is_same_v<const int, int>, "const int & int");
    static_assert(is_same_v<const volatile char, char>, "const volatile int & int");
    static_assert(is_same_v<double, volatile double>, "double & volatile double");
    static_assert(is_same_v<const int, int>, "const int & int");
    
    std::cout << "All tests passed successfully!\n";
}
