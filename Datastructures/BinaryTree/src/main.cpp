#include <iostream>
#include <limits>
#include <numeric>

#include "BinaryTree.hpp"


int main()
{
	BinaryTree<int> bt;
	bt.createTree();

	std::cout << std::boolalpha << bt.isStrict() << "\n";

	std::cin.get();
}