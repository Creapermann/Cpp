#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>

template<typename T>
bool isLower(T a, T b)
{
    return a < b;
}

template<typename T>
bool isGreater(T a, T b)
{
    return a > b;
}


template<typename T, int Size>
void sort(std::array<T, Size>& arr, bool (*compare)(T, T))
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        auto lowest{ i };

        for (int k = i + 1; k < arr.size(); k++)
        {
            if (compare(arr[k], arr[lowest]))
            {
                lowest = k;
            }
        }

        if (lowest != i)
        {
            std::swap(arr[lowest], arr[i]);
        }
    }
}


int main()
{
    std::array<double, 8> testArr{ 9.7, 2.1, 7.3, 6.9, 3.3, 5.0, 5.6, 8.8 };

    sort(testArr, isLower);

    for (auto i : testArr)
    {
        std::cout << i << " ";
    }

    std::cout << '\n';

    return 0;
}