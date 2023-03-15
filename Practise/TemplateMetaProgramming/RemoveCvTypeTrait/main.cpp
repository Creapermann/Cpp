#include <iostream>
#include <memory>
#include <string>
#include <cxxabi.h>



// Type identity
template<typename T>
struct type_identity
{
    using type = T;
};



// Remove const
template<typename T>
struct remove_const : type_identity<T> {};


template<typename T>
struct remove_const<T const> : type_identity<T> {};



// Remove volatile
template<typename T>
struct remove_volatile : type_identity<T> {};

template<typename T>
struct remove_volatile<T volatile> : type_identity<T> {};


// Remove const volatile
template<typename T>
using remove_cv = remove_volatile<typename remove_const<T>::type>;





template <typename T>
std::string TypeName()
{
    auto name = typeid(T()).name();  // function type, not a constructor call!
    int status = 0;

    std::unique_ptr<char, void(*)(void*)> res
    {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    std::string ret((status == 0) ? res.get() : name);
    if (ret.substr(ret.size() - 3) == " ()") ret.resize(ret.size() - 3);
    return ret;
}
#define TypeName(e) TypeName<decltype(e)>()



void println(const std::string& str)
{
    std::cout << str << "\n";
}


int main()
{
    const int iC = 3;
    println(TypeName(iC));
    println(TypeName<remove_const<decltype(iC)>::type>());

    println(std::string(""));

    volatile int iV = 4;
    println(TypeName(iV));
    println(TypeName<remove_volatile<decltype(iV)>::type>());

    println(std::string(""));


    const volatile int iCV = 5;
    println(TypeName(iCV));
    println(TypeName<remove_cv<decltype(iCV)>::type>());
}
