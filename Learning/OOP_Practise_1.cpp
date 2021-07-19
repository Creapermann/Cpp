#include <iostream>
#include <cassert>


class IntArray
{
private:
	int* m_array{nullptr};
	int m_size{0};

public:
	// Constructor
	IntArray(int size);

	IntArray(const IntArray& toCopy);


	// Destructor
	~IntArray();

	// Operator overloads
	int& operator[] (int index);
	IntArray& operator=(const IntArray& toCopy);

	friend std::ostream& operator<< (std::ostream& out, const IntArray& array);
};


IntArray::IntArray(int size)
	: m_size(size)
{
	assert(size > 0 && "The size needs to be bigger than 0!");
	m_array = new int[size];
}

IntArray::IntArray(const IntArray& toCopy)
	: m_size{toCopy.m_size}
{
	delete[] m_array;

	m_array = new int[toCopy.m_size];


	for (int i = 0; i < toCopy.m_size; ++i)
	{
		m_array[i] = toCopy.m_array[i];
	}
}



IntArray::~IntArray()
{
	delete[] m_array;
}



int& IntArray::operator[](int index)
{
	return *(m_array + index);
}

IntArray& IntArray::operator=(const IntArray& toCopy)
{
	// self assignment guard
	if (this == &toCopy)
	{
		return *this;
	}

	delete[] m_array;

	m_size = toCopy.m_size;
	m_array = new int[toCopy.m_size];


	for (int i = 0; i < toCopy.m_size; ++i)
	{
		m_array[i] = toCopy.m_array[i];
	}

	return *this;
}


std::ostream& operator<< (std::ostream& out, const IntArray& array)
{
	for (int i = 0; i < array.m_size; ++i)
	{
		out << *(array.m_array + i) << " ";
	}

	return out;
}



IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a };
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}