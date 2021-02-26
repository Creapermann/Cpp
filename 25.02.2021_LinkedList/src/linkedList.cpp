#include "linkedList.hpp"


#include <iostream>



LinkedList::LinkedList()
{
	headNode = nullptr;
	lastNode = headNode;
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

int LinkedList::getNode(int index) const
{
	Node* currNode = headNode;

	//Iterates through the LinkedList until it hits the given index
	for (int i = 0; i < index - 1; i++)
	{       //-1 cause we dont want the user to be forced to use 0-based indexing
		currNode = currNode->nextNodePtr;
	}

	//returns the index data
	return currNode->data;
}

void LinkedList::addNode(int n, int index)
{
	Node* temp = new Node(n);   //New Node
	Node* currNode = headNode;  //temp Node

	//This checks if the Node to add is the first node of the whole linked list, if thats the case,
	//it gets to be the "headNode"
	if (headNode == nullptr) {
		headNode = temp;
		lastNode = temp;
	}
	// < 1 means that there was no input for a location (index, this means where the node should be added in between),
	//so it just adds the Node to the end, by keeping track of the last Node with the private class variable "prevNode",
	//and just sets the pointer of the last Node from null to the new Node
	else if (index < 1) {
		lastNode->nextNodePtr = temp;
		lastNode = temp;
	}
	// == 1 means that the new Node should get set as the first Node of the linkedlist (headNode), so
	//it just sets the new Nodes pointer to the old headNode and sets the new Node as "headNode"
	else if (index == 1) {
		temp->nextNodePtr = headNode;
		headNode = temp;
	}
	//This means that the Node should be set somewhere in between Nodes, so
	//it gets the Node infront of the location where the new Node should be: e.g. 1, 2, 3, New Node, 4, it gets the 3
	//and sets the pointer of it to the new Node. The pointer of the new Node gets set to the Node behind
	//its location
	else {
		for (int i = 0; i < index - 1 - 1; i++) {    //the first -1 is cause we dont want the use to be forced to use 0-based indexing,
			currNode = currNode->nextNodePtr;        //this means, if he types in 3, the 3rd index should get choosen and not the 2nd one
		}                                            //cause of 0, 1, 2. The 2nd -1 is to get the Node infront of the new location

		temp->nextNodePtr = currNode->nextNodePtr;
		currNode->nextNodePtr = temp;
	}


	size++;
}

void LinkedList::deleteNode(int index)
{
	//temp Node pointer
	Node* currNode = headNode;

	//If the index is bigger than 1, it sets "currentNode" to the Node infront of the Node which should get deleted
	if (index > 1) {
		for (int i = 0; i < index - 1 - 1; i++) {    //the -1 -1 is for starting the linked list from index 1 and get the prev node
			currNode = currNode->nextNodePtr;            //The node infront on the node to delete
		}
		//else its "currNode" is initialized to headNode

		// > 1 works in this way: it gets the Node infront of the Node which should get deleted and sets its pointer to the
		//Node after the Node which should get deleted, then it deletes the node.
		int oldData = currNode->nextNodePtr->data;    //stores the data of the node which was deleted

		//First creates a variable to store the node after the one which is getting deleted, so it doesnt get lost.
		//After it deletes the the node and at the end, it sets the pointer of the node infront of the one which got
		//deleted to the temp variable with the Node after the deleted Node
		auto temp = currNode->nextNodePtr->nextNodePtr;
		delete currNode->nextNodePtr;
		currNode->nextNodePtr = temp;
		size--;

		std::cout << "deleted data: " << oldData << std::endl;
	}
	// == 1 works in this way: == 1 means that the first Node (the headNode) should get deleted. So it sets the secound 
	//Node as "headNode" (private class variable) and deletes the first Node.
	else if (index == 1) {
		int oldData = currNode->data;      //stores the data of the node which was deleted

		headNode = currNode->nextNodePtr;
		delete currNode;

		std::cout << "deleted data: " << oldData << std::endl;
	}
}

void LinkedList::print() const
{
	//prints all Nodes in the linkedlist
	Node* currNode = headNode;
	while (currNode != nullptr) {      //the last nodes pointer is set to null, so it checks if the current is the last
		std::cout << currNode->data << std::endl;
		currNode = currNode->nextNodePtr;
	}
}
