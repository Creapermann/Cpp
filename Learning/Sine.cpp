#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <string>
#include <fstream>



double sin(double x, int n)
{
    static double p{ 1 }, fCount{ 1 };

    if (n == 1)
        return x;

    double res = sin(x, n - 1);

    if (n == 2)         // First after base-case
    {
        p = x * x * x;
        fCount = 3;
    }
    else
    {
        p = p * x * x;
        fCount += 2;
    }

    int f{1};
    for (int i = 1; i < fCount + 1; ++i)
        f *= i;

    return (n % 2 == 0) ? (res - p / f) : (res + p / f);
}

int main()
{
    std::cout << sin(10, 5);
    std::cin.get();
}