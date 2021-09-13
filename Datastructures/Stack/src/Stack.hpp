#pragma once

#include <memory>
#include <initializer_list>
#include <vector>


template<typename T>
class Node
{
public:
	Node(T& data)
		: m_data{ data },  next{nullptr}
	{
	}

	T& data() { return m_data; };

	std::shared_ptr<Node<T>> next;

private:
	T m_data;
};


template<typename T>
class Stack
{
public:
	Stack();
	Stack(const std::vector<T>& vec);

	std::shared_ptr<Node<T>> begin() const;
	std::shared_ptr<Node<T>> end() const;
	std::size_t size() const;

	void clear();
	const T& top() const;
	void push(T data);
	void pop();

	void display() const;


private:
	std::shared_ptr<Node<T>> m_root;
	std::size_t m_size;
};


// class definition
#include "Stack.txx"