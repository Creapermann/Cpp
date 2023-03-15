#pragma once

#include <memory>
#include <initializer_list>
#include <functional>


template<typename T>
class Node
{
public:
    Node() = default;
    Node(T data)
        : m_data{data}, next{nullptr}
    {}

    operator T() const noexcept { return m_data; }

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
    LinkedList(std::initializer_list<T> init_list);

    
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
    public:

        Iterator()
            : m_ptr{nullptr}
        {}

        Iterator(std::shared_ptr<Node<T>> ptr)
            : m_ptr{ ptr }
        {
        }

        T& operator*() { return m_ptr->data(); };
        void operator++()    { if (m_ptr) { m_ptr = m_ptr->next; } else { throw std::out_of_range("Out of range"); } }
        void operator++(int) { if (m_ptr) { m_ptr = m_ptr->next; } else { throw std::out_of_range("Out of range"); } }
        void operator=(std::shared_ptr<Node<T>> ptr) { m_ptr = ptr; }

        template<typename U>
        void operator==(U cond) { return m_ptr == cond; }

    private:
        std::shared_ptr<Node<T>> m_ptr;
    };


private:
    std::size_t m_size;
    std::shared_ptr<Node<T>> m_root;
};


// Class definition
#include "LinkedList.txx"
