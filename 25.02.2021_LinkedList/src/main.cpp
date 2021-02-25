#include <iostream>
#include <string>
#include <vector>

class Node
{
public:
	Node(int n);

	int data;
	Node* nextNodePtr = nullptr;

private:

};

Node::Node(int n)
{
	data = n;
}




class LinkedList
{
public:
	LinkedList(int n);
	~LinkedList();

	int getNode(int index);
	void addNode(int n, int index);
	void deleteNode(int index);

private:
	Node* headNode = new Node(1);
	Node* prevNode = nullptr;

	int size = 1;
};

LinkedList::LinkedList(int n)
{
	Node* head = new Node(n);
	headNode = head;
	prevNode = head;
}

LinkedList::~LinkedList()
{
	Node* currNode = headNode;
	Node* oldNode = nullptr;

	//deletes all Nodes
	for (int i = 0; i < size; i++) {
		
		oldNode = currNode;
		currNode = currNode->nextNodePtr;
		delete oldNode;
	}

	delete headNode;
}

int LinkedList::getNode(int index)
{
	Node* currNode = headNode;
	
	//Iterates through the LinkedList until it hits the given index
	for (int i = 0; i < index - 1; i++) {       //-1 so that you get the first index of the linkedlist when entering  1
		currNode = currNode->nextNodePtr;
	}

	//returns the index data
	return currNode->data;
}

void LinkedList::addNode(int n, int index = 0)
{
	//creates a new node and sets the "nextNode" pointer of the previous node to the new node
	Node* temp = new Node(n);
	prevNode->nextNodePtr = temp;
	prevNode = temp;

	size++;
}

void LinkedList::deleteNode(int index)
{

	Node* prevNode = nullptr;
	Node* currNode = headNode;

	//Iterates through the LinkedList until it hits the given index
	if (index >= 1) {
		for (int i = 0; i < index - 1 - 1; i++) {    //the -1 -1 is for starting the linked list from index 1 and get the prev node
			currNode = currNode->nextNodePtr;            //The node infront on the node to delete
		}
	}
	else
		currNode = headNode;

	int tempData = currNode->nextNodePtr->data;
	currNode->nextNodePtr = currNode->nextNodePtr->nextNodePtr;
	size--;

	std::cout << "The node with the value: " << tempData << " was deleted!" << std::endl;
}





int main() 
{

	LinkedList ll(1);
	ll.addNode(2);
	ll.addNode(3);
	ll.addNode(4);
	ll.deleteNode(2);
	std::cout << ll.getNode(3) << std::endl;

	std::cin.get();
	return 0;
}