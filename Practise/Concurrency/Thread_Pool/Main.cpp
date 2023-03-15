#include <iostream>
#include <chrono>

#include "Thread_pool.hpp"


class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_type = std::chrono::steady_clock;
	using second_type = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_type> m_beg;

public:
	Timer() : m_beg{ clock_type::now() }
	{
	}

	void reset()
	{
		m_beg = clock_type::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
	}
};


bool isPrime(long long n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;

	for (long long i = 2; i < n / 2 + 1; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

long long nth_prime(long long n)
{
	int count{ 0 };

	long long i{ 0 };
	for (; count != n; ++i)
	{
		if (isPrime(i))
			++count;
	}
	return i - 1;
}



int main()
{
	try
	{
		Thread_pool tp;

		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "Starting: \n";
		tp.add_task([] { std::cout << nth_prime(9928) << "\n"; });
		tp.add_task([] { std::cout << nth_prime(2000) << "\n"; });
		tp.add_task([] { std::cout << nth_prime(3000) << "\n"; });
		tp.add_task([] { std::cout << nth_prime(8000) << "\n"; });
		tp.add_task([] { std::cout << nth_prime(9000) << "\n"; });
		tp.add_task([] { std::cout << nth_prime(3000) << "\n"; });
		tp.add_task([] { std::cout << nth_prime(1493) << "\n"; });
	}
	catch (std::exception e)
	{
		std::cout << "Exception:  " << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Non standard exception caught!\n";
	}
}