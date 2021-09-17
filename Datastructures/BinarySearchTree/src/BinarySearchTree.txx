#pragma once

#include "BinarySearchTree.hpp"



template<typename T>
BinarySearchTree<T>::BinarySearchTree()
	: m_root{nullptr}, m_nodesAmount{0}
{
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> init_list)
{
	for (auto& o : init_list)
	{
		insert(o);
	}
}



template<typename T>
std::size_t height_helper(const std::shared_ptr<Node<T>> ptr, const std::shared_ptr<Node<T>> root)
{
	if (!ptr)
		return 0;
	else
	{
		auto x = height_helper(ptr->left, root);
		auto y = height_helper(ptr->right, root);

		// Just add one so it gets to be height and not levels
		int add{};
		if (ptr != root)
			add = 1;

		return ((x >= y) ? x + add : y + add);
	}
}

template<typename T>
std::size_t BinarySearchTree<T>::height(std::shared_ptr<Node<T>> from) const
{
	return height_helper(from, from);
}

template<typename T>
std::size_t BinarySearchTree<T>::totalNodes() const
{
	return m_nodesAmount;
}

template<typename T>
std::shared_ptr<Node<T>> BinarySearchTree<T>::root()
{
	return m_root;
}


/// <summary>
/// Recursivly get to the right location and insert the new Node. Dont insert anything if a
/// Node with the same content already exists.
/// </summary>
template<typename T>
std::shared_ptr<Node<T>> insert_helper(std::shared_ptr<Node<T>> ptr, const T& toInsert)
{
	if (ptr == nullptr)        // right location found
	{
		auto temp = std::make_shared<Node<T>>(toInsert);
		return temp;
	}


	if (toInsert == ptr->data())   // Item already exists, do nothing
		return ptr;


	if (toInsert > ptr->data())
		ptr->right = insert_helper(ptr->right, toInsert);
	else
		ptr->left = insert_helper(ptr->left, toInsert);

	return ptr;
}

template<typename T>
void BinarySearchTree<T>::insert(const T& toInsert)
{
	if (!m_root)
		m_root = std::make_shared<Node<T>>(toInsert);
	else
		insert_helper(m_root, toInsert);
}


enum class cessor_type
{
	Undefined,
	Predecessor,
	Successor
};

/// <summary>
/// Check wether an node has a Successor or Predecessor and return it. If none is found, return nullptr
/// </summary>
template<typename T>
std::shared_ptr<Node<T>> find_cessor(std::shared_ptr<Node<T>> ptr, cessor_type& type)
{
	std::shared_ptr<Node<T>> curr = nullptr;
	if (ptr->right)
	{
		curr = ptr->right;
		while (curr->left)
		{
			curr = curr->left;
		}

		type = cessor_type::Successor;
		return curr;
	}
	else if(ptr->left)
	{
		curr = ptr->left;
		while (curr->right)
		{
			curr = curr->right;
		}

		type = cessor_type::Predecessor;
		return curr;
	}
	else
	{
		type = cessor_type::Undefined;
		return nullptr;
	}
}


/// <summary>
/// Remove an Node and replace it with its right cessor so the right order remains. Dont do 
/// anything if no node with the given value was found
/// </summary>
template<typename T>
void BinarySearchTree<T>::remove(const T& toRemove)
{
	auto toRemPtr = find(toRemove);

	if (!toRemPtr)
		return;

	if (!toRemPtr->hasChild())
	{
		auto parent = find_parent_of(toRemove);

		if (!parent)
		{
			m_root = nullptr;
			return;
		}

		if (parent->left->data() == toRemove)
			parent->left = nullptr;
		else
			parent->right = nullptr;
	}
	else
	{
		std::shared_ptr<Node<T>> cessor = nullptr;
		while (toRemPtr->hasChild())                // Remove the cessor after removing the object, if the cessor has childs
		{
			cessor_type type{ cessor_type::Undefined };
			cessor = find_cessor(toRemPtr, type);
			toRemPtr->data() = cessor->data();

			auto curr_height = height(toRemPtr);

			if (type == cessor_type::Successor && curr_height == 1)
				toRemPtr->right = nullptr;
			else if (type == cessor_type::Predecessor && curr_height == 1)
				toRemPtr->left = nullptr;


			toRemPtr = cessor;                     // Set the target to remove to cessor
		}
	}
}



/// <summary>
/// Return given node. If no node with the given value exists, return nullptr
/// </summary>
template<typename T>
std::shared_ptr<Node<T>> find_helper(std::shared_ptr<Node<T>> ptr, const T& toFind)
{
	if (ptr == nullptr)
		return nullptr;

	if (ptr->data() == toFind)
		return ptr;

	if (toFind > ptr->data())
		return find_helper(ptr->right, toFind);
	if (toFind < ptr->data())
		return find_helper(ptr->left, toFind);

	throw std::runtime_error("Unknown error occured");
	return nullptr;
}

template<typename T>
std::shared_ptr<Node<T>> BinarySearchTree<T>::find(const T& toFind) const
{
	return find_helper(m_root, toFind);
}


/// <summary>
/// Return the parent of a given node. If the a node with the given value does not exist,
/// or is the root node, return nullptr
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
std::shared_ptr<Node<T>> find_parent_of_helper(std::shared_ptr<Node<T>> ptr, const T& toFind, const std::shared_ptr<Node<T>> root)
{
	// Searched for parent -> no parent
	if (toFind == root->data())
		return nullptr;

	// Found
	if(ptr->left && ptr->left->data() == toFind)
		return ptr;
	if (ptr->right && ptr->right->data() == toFind)
		return ptr;


	if (toFind > ptr->data())
	{
		if (!ptr->right)		// Doesnt exist
			return nullptr;
		return find_parent_of_helper(ptr->right, toFind, root);
	}
	if (toFind < ptr->data())
	{
		if (!ptr->left)		// Doesnt exist
			return nullptr;
		return find_parent_of_helper(ptr->left, toFind, root);
	}

	throw std::runtime_error("Unknown error occured");
	return nullptr;
}

template<typename T>
std::shared_ptr<Node<T>> BinarySearchTree<T>::find_parent_of(const T& toFind) const
{
	return find_parent_of_helper(m_root, toFind, m_root);
}
