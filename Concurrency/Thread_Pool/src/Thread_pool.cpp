#include "Thread_pool.hpp"


Thread_pool::Thread_pool()
{
	const std::size_t max_threads = (std::thread::hardware_concurrency() <= 0) ? 2 : std::thread::hardware_concurrency();
	for (int i = 0; i < max_threads; ++i)
	{
		std::thread t{ &Thread_pool::check_for_task, this };
		m_vector.push_back(std::move(t));
	}
}


void Thread_pool::check_for_task()	
{
	while (true)
	{
		Func task;

		std::unique_lock lock(m_mutex);
		if (!m_queue.empty())
		{
			task = m_queue.pop();
			lock.unlock();
			task();
		}
		else
		{
			m_queue.m_new_task.wait(lock);
			task = m_queue.pop();
			lock.unlock();
			task();
		}
	}
}

void Thread_pool::pop_task()
{
	std::lock_guard lock{ m_mutex };
	m_queue.pop();
}

void Thread_pool::add_task(Func task)
{
	std::lock_guard lock{ m_mutex };
	m_queue.push(task);
}