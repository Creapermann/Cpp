#include <iostream>
#include <memory>
#include <array>


template<int size>
void merge(std::array<int, size>& arr, int low, int mid, int high)
{
    int i{ low };
    int k{ mid + 1 };
    int a{low};

    std::array<int, size> temp_arr;
    while (i <= mid && k <= high)
    {
        if (arr[i] < arr[k])
        {
            temp_arr[a++] = arr[i++];
        }
        else
        {
            temp_arr[a++] = arr[k++];
        }
    }
    for (;i <= mid; ++i) 
    { temp_arr[a++] = arr[i]; }
    for (;k <= high; ++k) 
    { temp_arr[a++] = arr[k]; }

    for (int c = low; c <= high; ++c)
    {
        arr[c] = temp_arr[c];
    }
}


template<int size>
void merge_sort(std::array<int, size>& arr, int low, int high)
{
    if (low < high)
    {
        auto mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


int main()
{ 
    std::array<int, 7> arr{4, 2, 1, 3, 4, 5, 2};
    merge_sort(arr, 0, static_cast<int>(arr.size() - 1));

    for (auto o : arr)
    {
        std::cout << o << " ";
    }

    std::cin.get();
}

