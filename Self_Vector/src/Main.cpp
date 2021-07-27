#include "Self_Vector.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <functional>


int main()
{
	Self_Vector<char> v;

	v.pushback('a');
	v.popback();

	v.clear();
	v.reverse();

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

	std::cin.get();
}