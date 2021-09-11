#include "Self_Vector.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <exception>

class Test
{
public:
	int a;
	int b;
};


int main()
{
	std::vector<int> l;

	Self_Vector<int> v;

	v.pushback(1);
	v.pushback(2);
	v.pushback(3);
	v.pushback(4);

	Self_Vector<int> v2;
	v2 = std::move(v);

	std::cout << "Content v:  ";
	for (std::size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];

		if (i != v.size() - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\nSize:     " << v.size() << "\n";
	std::cout << "Capacity: " << v.capacity() << "\n";


	std::cout << "\n\nContent v2:  ";
	for (std::size_t i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i];

		if (i != v2.size() - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\nSize:     " << v2.size() << "\n";
	std::cout << "Capacity: " << v2.capacity() << "\n";



	std::cout << "\n\n";

	std::cin.get();
}