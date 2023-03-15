#include <iostream>
#include <array>

#include "Hash.hpp"



int main()
{ 
    Hash hash{0, 10, 22, 2, 9, 3, 8, 78, 202, 222, 252};

    hash.insert(909);

    std::cout << std::boolalpha << ((hash.find(2)) ? true : false) << " ";
    std::cout << std::boolalpha << ((hash.find(7)) ? true : false) << " ";
    std::cout << std::boolalpha << ((hash.find(78)) ? true : false) << " ";

    std::cin.get();
}