#include <iostream>
#include <memory>
#include <exception>


template<typename T>
class Node
{
public:
    T m_data;
    std::shared_ptr<Node<T>> m_next;
    
    Node(T data);
};

template<typename T>
Node<T>::Node(T data)
    : m_data{data}, m_next{nullptr}
{
}



template <typename T>
class Queue
{
private:
    std::shared_ptr<Node<T>> m_first;
    std::weak_ptr<Node<T>> m_rare;

    std::size_t m_size;

public:
    Queue();

    void enqueue(const T& elem);
    T dequeue();
    void display();
};


template<typename T>
Queue<T>::Queue()
    : m_size{0}, m_first{nullptr}, m_rare{m_first}
{
}

template<typename T>
void Queue<T>::enqueue(const T& elem)
{
    if (!m_first)
    {
        m_first = std::make_shared<Node<T>>(elem);
        m_rare = m_first;
    }
    else
    {

        m_rare.lock()->m_next = std::make_shared<Node<T>>(elem);
        m_rare = m_rare.lock()->m_next;
    }
 
    ++m_size;
}

template<typename T>
T Queue<T>::dequeue()
{
    if (!m_first)
        return -1;

    T temp = m_first->m_data;
    m_first = m_first->m_next;

    return temp;
}

template<typename T>
void Queue<T>::display()
{
    std::shared_ptr<Node<T>> temp_ptr = m_first;
    
    while (temp_ptr)
    {
        std::cout << temp_ptr->m_data << " ";
        temp_ptr = temp_ptr->m_next;
    }
}


int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(7);

    std::cout << "\n";
    q.display();

    std::cin.get();
}