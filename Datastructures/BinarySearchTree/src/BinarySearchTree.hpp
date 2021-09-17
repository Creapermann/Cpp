#pragma once

#include <memory>
#include <iostream>
#include <initializer_list>


template<typename T>
class Node
{
public:
	Node(const T& data)
		: m_data{ data }, left{ nullptr }, right{ nullptr }
	{
	}

	T& data() { return m_data; };
	bool hasChild() { return (left || right); }

	std::shared_ptr<Node<T>> left;
	std::shared_ptr<Node<T>> right;

private:
	T m_data;
};



template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(std::initializer_list<T> init_list);

	std::size_t height(std::shared_ptr<Node<T>> from) const;
	std::size_t totalNodes() const;
	std::shared_ptr<Node<T>> root();

	void insert(const T& toInsert);
	void remove(const T& toRemove);

	std::shared_ptr<Node<T>> find(const T& toRemove) const;
	std::shared_ptr<Node<T>> find_parent_of(const T& toRemove) const;


private:
	std::shared_ptr<Node<T>> m_root;
	std::size_t m_nodesAmount;
};



// include class definition
#include "BinarySearchTree.txx"