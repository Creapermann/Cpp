#include <iostream>

int fib(long long n)
{
    static std::unordered_map<long long, long long> map;

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (map.find(n) == map.end())
	map.insert({n, fib(n - 1) + fib(n - 2) });
	
    return map.at(n);
}


int main()
{
    std::cout << fib(70) << "\n";

    std::cin.get();
}
