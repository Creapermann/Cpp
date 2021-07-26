#include "Self_Vector.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <functional>


int main()
{
	std::vector<int> a;


	Self_Vector<double> v2;

	Self_Vector<double> v{1, 2.0, 2.9, 3, 4, 5.2};

	v2 = v;

	v.pushback(0.3);
	v.sort();
	v.reverse();
	v.insert(3, 10.5);

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

	std::cout << std::boolalpha << v.contains(5.2) << "\n\n\n";

	std::cout << "Content:  ";
	for (int i = 0; i < v2.size(); i++)
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

	std::cout << std::boolalpha << v2.contains(5.2) << "\n";


	std::cin.get();
}