#include "Self_Vector.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <functional>


int main()
{
	Self_Vector<char> v;

	v.pushback('a');
	v.pushback('g');

	Self_Vector<char> v2 = v;
	v.reverse();



	std::cout << "Content v:  ";
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


	std::cout << "\n\nContent v2:  ";
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

	std::cin.get();
}