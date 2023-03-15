#include <iostream>

#include "Soundex.hpp"


int main(int argc, char* argv[])
{
    Soundex soundex;
    
    for(int i = 1; i < argc; ++i)
    {
        std::cout << soundex.encode(argv[i]) << "\n";
    }
        
    return 0;
}