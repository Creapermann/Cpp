#pragma once

#include <memory>


#include "BinaryTree.hpp"


template<typename T>
class Node
{
public:
	Node(const T& data)
		: m_data{ data }, left{ nullptr }, right{ nullptr }
	{
	}

	T& data() { return m_data; };

	std::shared_ptr<Node<T>> left;
	std::shared_ptr<Node<T>> right;

private:
	T m_data;
};



template<typename T>
class BinaryTree
{
public:
	BinaryTree();

	void createTree();

	std::size_t height();
	std::size_t total_nodes();
	std::size_t possible_permutations();

	bool isStrict();
	bool isFull();

	void preorder_display();
	void inorder_display();
	void postorder_display();
	void levelorder_display();


private:
	std::shared_ptr<Node<T>> m_root;
	std::size_t m_nodesAmount;
};


// include class definition
#include "BinaryTree.txx"