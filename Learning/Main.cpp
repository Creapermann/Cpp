#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>


bool isLower(int a, int b)
{
    return a < b;
}

bool isGreater(int a, int b)
{
    return a > b;
}


template<typename T, int Size>
void sort(std::array<T, Size>& arr, bool (*compare)(T, T))
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        auto lowest{i};

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
    std::array<int, 8> testArr{9, 2, 7, 6, 3, 5, 5, 8};

    sort(testArr, isGreater);

    for (int i : testArr)
    {
        std::cout << i << " ";
    }

    std::cout << '\n';

    return 0;
}