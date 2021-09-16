#include <iostream>

#include "BinarySearchTree.hpp"



int main()
{
	BinarySearchTree<int> bs;
	bs.insert(10);
	bs.insert(90);
	bs.insert(20);
	bs.insert(80);
	bs.insert(30);
	bs.insert(70);

	bs.remove(10);

	std::cin.get();
}