#pragma once
#include "LinkedList.hpp"

#include <algorithm>


template<typename T>
LinkedList<T>::LinkedList()
	: m_root{nullptr}, m_size{0}
{
}

/// <summary>
/// Creates a linked-list copy of a vector
/// </summary>
template<typename T>
LinkedList<T>::LinkedList(std::vector<T> init_list)
	: m_size{ init_list.size() }
{
	if (init_list.empty())
		return;

	m_root = std::make_shared<Node<T>>(Node<T>(init_list[0]));

	auto curr = m_root;
	for (int i{ 1 }; i < init_list.size(); ++i)
	{
		auto temp_node{ std::make_shared<Node<T>>(Node<T>(init_list[i])) };
		curr->next = temp_node;
		temp_node->prev = curr;

		curr = temp_node;
	}
}



template<typename T>
Node<T>& LinkedList<T>::operator[](std::size_t index)
{
	if (index < 0 || index > m_size - 1)
		throw std::out_of_range;

	auto curr = m_root;
	for (int i{ 0 }; i < index; ++i)
	{
		curr = curr->next;
	}

	return curr;
}



template<typename T>
std::size_t LinkedList<T>::size() const
{
	return m_size;
}

template<typename T>
std::shared_ptr<Node<T>> LinkedList<T>::begin() const
{
	return m_root;
}

template<typename T>
std::shared_ptr<Node<T>> LinkedList<T>::end() const
{
	if (empty())
		return nullptr;

	std::shared_ptr<Node<T>> curr = m_root;
	for (int i{ 0 }; i < m_size - 1; ++i)
	{
		curr = curr->next;
	}

	return curr;
}

template<typename T>
bool LinkedList<T>::empty() const
{
	return (m_size == 0 ? true : false);
}


template<typename T>
void LinkedList<T>::insert(std::size_t index, T data)
{
	if (index == 0)
	{
		push_front(data);
		return;
	}
	if (index == m_size)
	{
		push_back(data);
		return;
	}
	if (index < 0 || index > m_size)
		throw std::out_of_range("Out of range");


	auto curr = m_root;
	for (int i{ 0 }; i < index - 1; ++i)
	{
		curr = curr->next;
	}

	auto temp_node = std::make_shared<Node<T>>(data);
	
	temp_node->next = curr->next;
	curr->next = temp_node;
	temp_node->prev = curr;
	temp_node->next->prev = temp_node;

	++m_size;
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
	std::shared_ptr<Node<T>> temp_node = std::make_shared<Node<T>>(data);

	if (empty())
	{
		m_root = temp_node;
	}
	else
	{
		std::shared_ptr<Node<T>> last_node(end());
		temp_node->prev = last_node;
		last_node->next = temp_node;
	}

	++m_size;
}

template<typename T>
void LinkedList<T>::push_front(T data)
{
	auto temp_node = std::make_shared<Node<T>>(data);
	std::shared_ptr<Node<T>> first_node = m_root;



	if(!empty())
	{

		temp_node->next = first_node;
		first_node->prev = temp_node;
	}

	m_root = temp_node;
	++m_size;
}

template<typename T>
void LinkedList<T>::remove(std::size_t index)
{
	if (index < 0 || index > m_size - 1)
		throw std::out_of_range("Out of range");
	if (index == 0)
	{
		pop_front();
		return;
	}
	if (index == m_size - 1)
	{
		pop_back();
		return;
	}

	auto curr = m_root;
	for (int i{ 0 }; i < index - 1; ++i)
	{
		curr = curr->next;
	}

	curr->next = curr->next->next;
	curr->next->prev = curr;

	--m_size;
}

template<typename T>
void LinkedList<T>::pop_back()
{
	if (empty())
		return;

	auto curr = m_root;
	for (int i{ 0 }; i < m_size - 1; ++i)
	{
		curr = curr->next;
	}

	if (m_root == curr)
		m_root.reset();
	else
		curr->prev.lock()->next = nullptr;

	--m_size;
}

template<typename T>
void LinkedList<T>::pop_front()
{
	if (empty())
		return;

	m_root = m_root->next;

	--m_size;
}

template<typename T>
void LinkedList<T>::clear()
{
	m_root = nullptr;
	m_size = 0;
}

template<typename T>
void LinkedList<T>::display() const
{
	auto curr = m_root;
	while (curr)
	{
		std::cout << curr->data() << " ";
		curr = curr->next;
	}
	std::cout << "\n";
}

template<typename T>
std::vector<T> LinkedList<T>::toVector()
{
	std::vector<T> vec;

	std::shared_ptr<Node<T>> curr = begin();
	while (curr)
	{
		vec.push_back(curr->data());
		curr = curr->next;
	}

	return vec;
}
