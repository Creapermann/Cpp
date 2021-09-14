#pragma once

#include <memory>
#include <initializer_list>


template<typename T>
class Node
{
public:
	Node(const T& data)
		: m_data{ data }, next{ nullptr }
	{
	}

	T& data() { return m_data; };

	std::shared_ptr<Node<T>> next;

private:
	T m_data;
};



template<typename T>
class DeQueue
{
public:
	DeQueue();
	DeQueue(std::initializer_list<T> init_list);


	std::shared_ptr<Node<T>> begin() const;
	std::shared_ptr<Node<T>> end() const;
	std::size_t size() const;
	bool empty() const;
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();

	void display() const;


private:
	std::shared_ptr<Node<T>> m_front;
	std::weak_ptr<Node<T>> m_rear;

	std::size_t m_size;
};


// include definition
#include "DeQueue.txx"