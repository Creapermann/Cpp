#include <iostream>

#include "node.hpp"
#include "linkedList.hpp"




int main() 
{

	LinkedList ll;

	ll.addNode(2);
	ll.addNode(1, 1);

	ll.print();



	std::cout << "size of linked list: " << ll.getSize() << std::endl;


	std::cin.get();
	return 0;
}