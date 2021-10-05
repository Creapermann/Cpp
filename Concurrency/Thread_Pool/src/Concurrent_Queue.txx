#include "Concurrent_Queue.hpp"



template<typename T>
void Concurrent_queue<T>::push(T elem)
{
	std::lock_guard lock{ m_mutex };
	m_queue.push(std::move(elem));
	m_new_task.notify_one();
}

template<typename T>
bool Concurrent_queue<T>::empty()
{
	std::lock_guard lock{ m_mutex };
	return m_queue.empty();
}

template<typename T>
T Concurrent_queue<T>::pop()
{
	std::lock_guard lock{ m_mutex };

	if (m_queue.empty())
		throw Concurrent_queue_empty();

	try
	{
		auto temp = m_queue.front();
		m_queue.pop();
		return temp;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}
}