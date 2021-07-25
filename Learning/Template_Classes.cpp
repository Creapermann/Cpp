#include <iostream>
#include <string>

template<class T, class U>
class Pair
{
protected:
	T m_val1{};
	U m_val2{};

public:
	// Constructors
	Pair(const T& first, const U& second);

	// Destructors
	virtual ~Pair() = default;


	// Memer-functions
	const T& first() const;
	const U& second() const;

	virtual std::ostream& print(std::ostream& out) const;


	// Operator-overloads
	template <typename T, U>
	friend std::ostream& operator<<(std::ostream& out, const Pair<T, U>& pair);
};


template<typename T, typename U>
Pair<T, typename U>::Pair(const T& first, const U& second)
	: m_val1{first}, m_val2{second}
{
}


template<typename T, typename U>
const T& Pair<T, U>::first() const
{
	return m_val1;
}

template<typename T, typename U>
const U& Pair<T, U>::second() const
{
	return m_val2;
}

template<typename T, typename U>
std::ostream& Pair<T, U>::print(std::ostream& out) const
{
	out << m_val1 << " " << m_val2;

	return out;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const Pair<T, U>& pair)
{
	return pair.print(out);
}





template <class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string str, T n);

};

template <typename T>
StringValuePair<T>::StringValuePair(std::string str, T n)
	: Pair<std::string, T>(str, n)
{
}


int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	std::cout << "\n" << svp << "\n";

	return 0;
}