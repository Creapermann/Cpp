#pragma once

#include <functional>
#include <vector>
#include <mutex>

#include "Concurrent_Queue.hpp"


using Func = std::function<void()>;


class Thread_pool
{
public:
	Thread_pool();

	Thread_pool(Thread_pool& rhs) = delete;
	Thread_pool& operator=(Thread_pool& rhs) = delete;

	Thread_pool(Thread_pool&& rhs) = delete;
	Thread_pool& operator=(Thread_pool&& rhs) = delete;

	~Thread_pool() { std::for_each(m_vector.begin(), m_vector.end(), [&](std::thread& t) { t.join(); }); }


	void add_task(Func task);


private:
	std::thread m_thread;
	std::mutex m_mutex;
	std::mutex m_double_lock;
	Concurrent_queue<Func> m_queue;
	std::vector<std::thread> m_vector;

private:
	void pop_task();
	void check_for_task();
};