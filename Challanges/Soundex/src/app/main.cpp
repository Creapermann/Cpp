#include <iostream>

#include "Soundex.hpp"


int main(int argc, char* argv[])
{
    std::cout << "Hello world!\n";
    
    Soundex s;
    s.encode("afhf");
    
    return 0;
}