#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <string>
#include <fstream>
#include <array>
#include <chrono> // for std::chrono functions




void TOH(int n, int A, int B, int C) 
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        std::cout << "From " << A << " to " << C << "\n";
        TOH(n-1, B, A, C);
    }
}




int main()
{
    TOH(5, 1, 2, 3);

    std::cin.get();
}