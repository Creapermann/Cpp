#include <iostream>
#include <memory>
#include <array>


template<int size>
int partition(std::array<int, size>& arr, int low, int high)
{
    int i{low}, k{ high }, pivot{arr[low]};
    do
    {
        while (arr[i] <= pivot && i < high - 1)
        { ++i; }
        do { --k; } while (arr[k] > pivot);

        if (i <= k)
            std::swap(arr[i], arr[k]);
    } 
    while (i < k);

    std::swap(arr[low], arr[k]);

    return k;
}


template<int size>
void QuickSort(std::array<int, size>& arr, int low, int high)
{
    if (arr.size() <= 1)
        return;

    if (low < high)
    {
        int pivot{ partition(arr, low, high) };

        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}


int main()  
{ 
    std::array<int, 7> arr{4, 1, 3, 9, 2, 7, 6};
    QuickSort(arr, 0, arr.size());

    for (auto o : arr)
    {
        std::cout << o << " ";
    }

    std::cin.get();
}

