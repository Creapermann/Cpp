#include <iostream>
#include <deque>

#include "DeQueue.hpp"


int main()
{
	DeQueue<int> dequeue({1,2,3,4,5});
	dequeue.push_back(3);
	dequeue.push_back(3);
	dequeue.push_back(3);
	dequeue.push_back(3);
	dequeue.push_front(-1);
	dequeue.pop_back();
	
	std::cout << std::boolalpha << dequeue.empty() << " ";

	dequeue.display();

	dequeue.pop_back();
	dequeue.pop_back();

	std::cout << std::boolalpha << dequeue.empty() << " ";


	std::cin.get();
}