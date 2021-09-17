#include <iostream>

#include "BinarySearchTree.hpp"



int main()
{
	BinarySearchTree<int> bs;
	bs.insert(15);
	bs.insert(20);
	bs.insert(25);
	bs.insert(30);
	bs.insert(35);
	
	auto h = bs.height(bs.root());

	std::cin.get();
}