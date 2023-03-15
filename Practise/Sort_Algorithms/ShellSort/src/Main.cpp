#include <iostream>
#include <array>


template<int T>
void shell_sort(std::array<int, T>& arr)
{
    int k{ 0 };
    for (int i{ (static_cast<int>(arr.size())) / 2 }; i >= 1; i /= 2)
    {
        k = 0;
        while (k + i <= arr.size() - 1)
        {
            if (arr[k] > arr[k + i])
            {
                std::swap(arr[k], arr[k + i]);

                int temp{ k };
                while (temp - i >= 0)
                {
                    if (arr[temp] < arr[temp - i])
                        std::swap(arr[temp], arr[temp - i]);

                    temp -= i;
                }
            }
            
            ++k;
        }
    }
}



int main()
{ 
    std::array<int, 8> arr{4, 8, 1, 3, 4, 5, 2, 9};
    shell_sort(arr);

    for (auto o : arr)
    {
        std::cout << o << " ";
    }

    std::cin.get();
}
