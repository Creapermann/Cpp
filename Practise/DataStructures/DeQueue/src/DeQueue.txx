#pragma once

#include <iostream>

#include "DeQueue.hpp"


template<typename T>
DeQueue<T>::DeQueue()
	: m_front{nullptr}, m_size{0}
{
}


template<typename T>
DeQueue<T>::DeQueue(std::initializer_list<T> init_list)
	: m_front{ nullptr }, m_size{ init_list.size() }
{
	std::shared_ptr<Node<T>> curr{ nullptr };

	std::size_t count{ 0 };
	for (auto& o : init_list)
	{
		if (count == 0)           // On first node
		{
			std::shared_ptr<Node<T>> temp_node{ std::make_shared<Node<T>>(o) };
			m_front = temp_node;
			curr = m_front;
			++count;
		}
		else
		{
			std::shared_ptr<Node<T>> temp_node{ std::make_shared<Node<T>>(o) };
			curr->next = temp_node;
			curr = curr->next;
		}
	}

	m_rear = curr;
}


template<typename T>
std::shared_ptr<Node<T>> DeQueue<T>::begin() const
{
	return m_front;
}


template<typename T>
std::shared_ptr<Node<T>> DeQueue<T>::end() const
{
	return m_rear;
}


template<typename T>
std::size_t DeQueue<T>::size() const
{
	return m_size;
}


template<typename T>
bool DeQueue<T>::empty() const
{
	return m_size == 0;
}


template<typename T>
void DeQueue<T>::display() const
{
	auto curr = m_front;

	while (curr)
	{
		std::cout << curr->data() << " ";
		curr = curr->next;
	}
}



template<typename T>
void DeQueue<T>::push_back(T data)
{
	std::shared_ptr<Node<T>> temp_node{ std::make_shared<Node<T>>(data) };
	m_rear.lock()->next = temp_node;
	m_rear = m_rear.lock()->next;
	
	++m_size;
}


template<typename T>
void DeQueue<T>::push_front(T data)
{
	std::shared_ptr<Node<T>> temp_node{ std::make_shared<Node<T>>(data) };
	temp_node->next = m_front;
	m_front = temp_node;
	
	++m_size;
}


template<typename T>
void DeQueue<T>::pop_back()
{
	if (empty())
		return;

	if (m_size == 1)
	{
		m_front = nullptr;
		--m_size;
		return;
	}

	// Bring curr infront of m_rear
	auto curr = m_front;
	while (curr->next != m_rear.lock())
	{
		curr = curr->next;
	}

	curr->next = nullptr;
	m_rear = curr;

	--m_size;
}


template<typename T>
void DeQueue<T>::pop_front()
{
	if (empty())
		return;

	m_front = m_front->next;

	--m_size;
}