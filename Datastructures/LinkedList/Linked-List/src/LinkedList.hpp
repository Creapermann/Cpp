#pragma once

#include <memory>
#include <initializer_list>
#include <functional>


template<typename T>
class Node
{
public:
    Node() = default;
    Node(T& data)
        : m_data{data}, next{nullptr}
    {}

    T& data() { return m_data; }
    void data(T obj) { data = obj; }

    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;

private:
    
    T m_data;
};



template<typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(std::vector<T> init_list);

    
    Node<T>& operator[](std::size_t index);

    
    std::size_t size() const;
    std::shared_ptr<Node<T>> begin() const;
    std::shared_ptr<Node<T>> end() const;
    bool empty() const;

    void insert(std::size_t index, T data);
    void push_back(T data);
    void push_front(T data);

    void remove(std::size_t index);
    void pop_back();
    void pop_front();

    void clear();
    void display() const;
    std::vector<T> toVector();

    class Iterator
    {
    };


private:
    std::size_t m_size;
    std::shared_ptr<Node<T>> m_root;
};


// Class definition
#include "LinkedList.txx"
