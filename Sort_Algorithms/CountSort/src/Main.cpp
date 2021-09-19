#include <iostream>
#include <memory>
#include <array>


template<int size>
void count_sort(std::array<int, size>& arr)
{
    int max{ 0 };
    for (auto o : arr)
    {
        if (o > max)
            max = o;
    }

    int* index_count_arr = new int[max + 1]{0};
    for (auto o : arr)
    {
        ++index_count_arr[o];
    }


    int pos{ 0 };
    for (int i{ 0 }; i <= max; ++i)
    {
        for (int k{ 0 }; k < index_count_arr[i]; ++k)
        {
            arr[pos] = i;
            ++pos;
        }
    }
}


int main()
{ 
    std::array<int, 7> arr{4, 2, 1, 3, 4, 5, 2};
    count_sort(arr);

    for (auto o : arr)
    {
        std::cout << o << " ";
    }

    std::cin.get();
}

