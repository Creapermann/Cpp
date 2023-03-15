#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <limits>

#include "BinaryTree.hpp"



template<typename T>
inline BinaryTree<T>::BinaryTree()
	: m_root{nullptr}, m_nodesAmount{0}
{
}


template<typename T>
void BinaryTree<T>::createTree()
{
	// Root node
	std::cout << "Your root node: ";
	T val;
	std::cin >> val;

	if (std::cin.bad())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return;
	}

	m_root = { std::make_shared<Node<T>>(val) };


	std::queue<std::shared_ptr<Node<T>>> queue;
	queue.push(m_root);
	++m_nodesAmount;

	
	// Iterates level for level, children of one level get pushed into the queue and iterated over the next level 
	while (!queue.empty())
	{
		system("CLS");
		
		std::cout << "Enter \"stop\" for none\n";

		{
			std::cout << "Enter left child for " << queue.front()->data() << ": ";
			T input;
			std::cin >> input;

			if (std::cin.good())
			{
				auto temp_node = std::make_shared<Node<T>>(input);
				queue.front()->left = temp_node;
				queue.push(temp_node);
				++m_nodesAmount;
			}
			else    // User choosed to stop
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		{
			std::cout << "Enter right child for " << queue.front()->data() << ": ";
			T input;
			std::cin >> input;

			if (std::cin.good())  // T is a string or the input was valid
			{
				auto temp_node = std::make_shared<Node<T>>(input);
				queue.front()->right = temp_node;
				queue.push(temp_node);
				++m_nodesAmount;
			}
			else    // User choosed to stop
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		queue.pop();        // Finished with element
	}
}


template<>
void BinaryTree<std::string>::createTree()
{
	// Root node
	std::cout << "Your root node: ";
	std::string val;
	std::cin >> val;
	
	if (std::cin.bad())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return;
	}

	m_root = { std::make_shared<Node<std::string>>(val) };


	std::queue<std::shared_ptr<Node<std::string>>> queue;
	queue.push(m_root);


	while (!queue.empty())
	{
		system("CLS");

		std::cout << "Enter \"stop\" for none\n";

		{
			std::cout << "Enter left child for " << queue.front()->data() << ": ";
			std::string input;
			std::cin >> input;

			if (std::cin.good() && input != "stop")  // T is a string or the input was valid
			{
				auto temp_node = std::make_shared<Node<std::string>>(input);
				queue.front()->left = temp_node;
				queue.push(temp_node);
				++m_nodesAmount;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		{
			std::cout << "Enter right child for " << queue.front()->data() << ": ";
			std::string input;
			std::cin >> input;

			if (std::cin.good() && input != "stop")  // T is a string or the input was valid
			{
				auto temp_node = std::make_shared<Node<std::string>>(input);
				queue.front()->right = temp_node;
				queue.push(temp_node);
				++m_nodesAmount;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		queue.pop();
	}
}


template<typename T>
std::size_t Rheight_helper(std::shared_ptr<Node<T>> ptr, std::shared_ptr<Node<T>> root)
{
	if (ptr)
	{
		auto x = Rheight_helper(ptr->left, root);
		auto y = Rheight_helper(ptr->right, root);

		if (ptr == root) return ((x >= y) ? x : y);      // Dont increase at the last return (else output is levels not height)
		else return ((x >= y) ? x : y) + 1;
	}
	return 0;
}

template<typename T>
std::size_t BinaryTree<T>::height()
{
	return Rheight_helper(m_root, m_root);
}


template<typename T>
std::size_t BinaryTree<T>::total_nodes()
{
	return m_nodesAmount;
}


template<typename T>
std::size_t BinaryTree<T>::possible_permutations()
{
	// Formula:
	// 2n
	//   C
	//    n
	// ________
	//  n + 1
	//
	// 
	// Example:
	// n = 5
	// 
	// 10x9x8x7x6
	// __________
	// 5x4x3x2x1
	// __________
	//    n+1


	std::size_t top{1};
	std::size_t bottom{ 1 };
	for (int i = (m_nodesAmount * 2); i > 0; --i)
	{
		if (i > m_nodesAmount)
			top *= i;
		else
			bottom *= i;
	}

	return (top / bottom) / (m_nodesAmount + 1);
}


template<typename T>
bool isStrictHelper(std::shared_ptr<Node<T>> ptr)
{
	if (ptr)
	{
		if (static_cast<bool>(ptr->left) != static_cast<bool>(ptr->right))
			return false;

		isStrictHelper(ptr->left);
		isStrictHelper(ptr->right);
	}
	else
	{
		return true;
	}
}

template<typename T>
bool BinaryTree<T>::isStrict()
{
	return isStrictHelper(m_root);
}


bool isFullHelper(std::size_t nodes_to_test)
{
	// Pattern:
	// full height n has height (n-1)*2 + 1 nodes
	// full height 1 has 3 nodes
	// 
	// 
	// Example:
	// n = 4
	// 
	// 1*2+1  = 3
	// 3*2+1  = 7
	// 7*2+1  = 15
	// 15*2+1 = 31   <--- result


	static std::size_t curr{3};

	if (curr == nodes_to_test)
		return true;
	else if(curr > nodes_to_test)
		return false;
	else
	{
		curr = (curr * 2) + 1;
		isFullHelper(nodes_to_test);
	}
}

template<typename T>
bool BinaryTree<T>::isFull()
{
	return isFullHelper(m_nodesAmount);
}



template<typename T>
void preorder_display_helper(std::shared_ptr<Node<T>> ptr)
{
	if(ptr)
	{
		std::cout << ptr->data() << " ";
		preorder_display_helper(ptr->left);
		preorder_display_helper(ptr->right);
	}
}

template<typename T>
void BinaryTree<T>::preorder_display()
{
	preorder_display_helper(m_root);
}



template<typename T>
void inorder_display_helper(std::shared_ptr<Node<T>> ptr)
{
	if (ptr)
	{
		inorder_display_helper(ptr->left);
		std::cout << ptr->data() << " ";
		inorder_display_helper(ptr->right);
	}
}

template<typename T>
void BinaryTree<T>::inorder_display()
{
	inorder_display_helper(m_root);
}



template<typename T>
void postorder_display_helper(std::shared_ptr<Node<T>> ptr)
{
	if (ptr)
	{
		postorder_display_helper(ptr->left);
		postorder_display_helper(ptr->right);
		std::cout << ptr->data() << " ";
	}
}

template<typename T>
void BinaryTree<T>::postorder_display()
{
	postorder_display_helper(m_root);
}


template<typename T>
void BinaryTree<T>::levelorder_display()
{
	std::queue<std::shared_ptr<Node<T>>> toVisit;
	toVisit.push(m_root);

	while (!toVisit.empty())
	{
		std::cout << toVisit.front()->data() << " ";

		if (toVisit.front()->left)
			toVisit.push(toVisit.front()->left);
		
		if (toVisit.front()->right)
			toVisit.push(toVisit.front()->right);

		toVisit.pop();
	}
}
