#pragma once

#include <memory>
#include <array>
#include <iostream>


class Node
{
public:
	Node(int d) 
		: m_data{d}, next{nullptr}
	{}

	int& data() { return m_data; };


	std::shared_ptr<Node> next;

private:
	int m_data;
};


class Hash
{
public:
	Hash() = default;
	Hash(std::initializer_list<int> init_list);

	void insert(int item);
	int* find(int item);


	std::array<std::shared_ptr<Node>, 10> m_table;

private:
	int hash(int key);

};