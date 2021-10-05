#pragma once

#include <mutex>
#include <queue>
#include <iostream>
#include <condition_variable>


class Concurrent_queue_empty : public std::exception
{
	const char* what() const override { return "Accessing an empty queue is illegal"; };
};



template<typename T>
class Concurrent_queue
{
private:
	std::queue<T> m_queue;
	std::mutex m_mutex;

public:
	Concurrent_queue() = default;

	void push(T elem);
	bool empty();
	T pop();

	std::condition_variable m_new_task;
};


// Include definition
#include "Concurrent_Queue.txx"