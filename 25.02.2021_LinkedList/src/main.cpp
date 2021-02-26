#include <iostream>

#include "node.hpp"
#include "linkedList.hpp"




int main() 
{

	LinkedList ll;

	ll.addNode(1);
	ll.addNode(2);
	ll.addNode(3);
	ll.addNode(4);
	ll.addNode(5);

	ll.reverse();

	ll.print();



	std::cout << "size of linked list: " << ll.getSize() << std::endl;


	std::cin.get();
	return 0;
}