#pragma once

#include "node.hpp"


class LinkedList
{

public:
	LinkedList();
	~LinkedList();

	int getNode(int index) const;
	void addNode(int n, int index = -1);
	void deleteNode(int index);
	void reverse();

	inline int getSize() const { return size; };
	void print() const;

private:
	int size = 0;
	Node* headNode = nullptr;
	Node* lastNode = headNode;

};