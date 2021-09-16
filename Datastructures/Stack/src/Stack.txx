#pragma once

#include "Stack.hpp"



template<typename T>
Stack<T>::Stack()
	: m_root{nullptr}, m_size{0}
{
}

template<typename T>
Stack<T>::Stack(std::vector<T> vec)
{
	if (!vec.empty())
	{
		// Setup first element
		std::shared_ptr<Node<T>> temp_node = std::make_shared<Node<T>>(vec[0]);
		m_root = temp_node;
	}

	auto curr = m_root;
	for (int i{ 1 }; i < vec.size(); ++i)
	{
		std::shared_ptr<Node<T>> temp_node = std::make_shared<Node<T>>(vec[i]);
		curr->next = temp_node;
		curr = curr->next;
	}
}


template<typename T>
std::shared_ptr<Node<T>> Stack<T>::begin() const
{
	return m_root;
}

template<typename T>
std::shared_ptr<Node<T>> Stack<T>::end() const
{
	auto curr = m_root;
	while (curr->next)
	{
		curr = curr->next;
	}

	return curr;
}

template<typename T>
std::size_t Stack<T>::size() const
{
	return m_size;
}

template<typename T>
void Stack<T>::clear()
{
	m_root = nullptr;
	m_size = 0;
}

template<typename T>
const T& Stack<T>::top() const
{
	return end()->data();
}

template<typename T>
void Stack<T>::push(T data)
{
	std::shared_ptr<Node<T>> temp_node = std::make_shared<Node<T>>(data);

	if (m_root == nullptr)
	{
		m_root = temp_node;
	}
	else
	{
		auto last_node = end();
		last_node->next = temp_node;
	}

	++m_size;
}

template<typename T>
void Stack<T>::pop()
{
	auto curr = m_root;
	for (int i{ 0 }; i < m_size - 2; ++i)
	{
		curr = curr->next;
	}

	curr->next = nullptr;

	--m_size;
}

template<typename T>
void Stack<T>::display() const
{
	auto curr = m_root;
	while (curr)
	{
		std::cout << curr->data() << " ";
		curr = curr->next;
	}
}
