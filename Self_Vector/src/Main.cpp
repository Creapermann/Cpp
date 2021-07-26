#include "Self_Vector.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <functional>


int main()
{
	Self_Vector<double> v{1, 2.0, 2.9, 3, 4, 5.2};

	v.pushback(0.3);

	v.sort();

	std::cout << "Content:  ";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];

		if (i != v.size() - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\nSize:     " << v.size() << "\n";
	std::cout << "Capacity: " << v.capacity() << "\n";

	std::cout << "\n\n";

	std::cout << std::boolalpha << v.contains(5.2) << "\n";


	std::cin.get();
}