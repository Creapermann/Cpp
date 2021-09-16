#include <iostream>
#include <limits>
#include <numeric>

#include "BinaryTree.hpp"



int main()
{
	BinaryTree<int> bt;
	bt.createTree();

	std::cout << "pre: ";
	bt.preorder_display();
	std::cout << "\n";

	std::cout << "in: ";
	bt.inorder_display();
	std::cout << "\n";

	std::cout << "post: ";
	bt.postorder_display();
	std::cout << "\n";

	std::cout << "level: ";
	bt.levelorder_display();
	std::cout << "\n";


	std::cin.get();
}