#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>




/* Character duplication in string using bitwise operations*/
int main()
{
    const char* str = "This_is_aTest";

    int x{}, y{};
    for (int i = 0; str[i] != '\0'; ++i)
    {
        x = 1;
        x = x << static_cast<int>(str[i]) - 97;

        if (x & y)
        {
            std::cout << str[i] << " exists more than one time\n";
        }
        else
        {
            y = x | y;
        }
    }


    std::cin.get();
    return 0;
}