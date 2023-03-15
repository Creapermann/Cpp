#include <compare>
#include <exception>
#include <ios>
#include <iostream>
#include <string>
#include "bad_expected_access.hpp"
#include "expected.hpp"
#include "unexpected.hpp"

using namespace my_std;

//class ComplexType
//{
//public:
//    ComplexType(int x)
//    {
//        y = x;
//    }

//    int y;
//};

expected<int, std::string> divideInts(int x, int y)
{
    //    if(y == 0)
    //        return unexpected(std::string("Cant divide by 0"));
    
    //    return x/y;
}

int main()
{
    expected<int, std::string> ex = 3;
    std::cout << std::boolalpha << ex.hasValue() << '\n';
    
    //    auto result = divideInts(10,2);
    //    if(result)
    //    {
    //        std::cout << result.value() << '\n';
    //    }
    //    else
    //    {
    //        std::cout << "There was an error: " << result.error().getError() << '\n';
    //    }
    
    return 0;
}
