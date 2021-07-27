#include "Self_Vector.hpp"

#include <cassert>
#include <algorithm>


// Constructors
template<typename T>
Self_Vector<T>::Self_Vector(const std::initializer_list<T>& list)
	: m_capacity{ list.size() }, m_size{ list.size() }
{
	m_array = new T[m_capacity];

	std::size_t count{ 0 };
	for (T i : list)
	{
		m_array[count] = i;
		++count;
	}
}

template<typename T>
Self_Vector<T>::Self_Vector(const std::size_t cap)
	: m_capacity{ cap }
{
	m_array = new T[m_capacity];
}



template<class T>
Self_Vector<T>::Self_Vector(Self_Vector& const toCopy)
	: m_capacity(toCopy.m_capacity), m_size(toCopy.m_size)
{
	m_array = new T[toCopy.m_capacity];
	std::copy(toCopy.m_array, toCopy.m_array + toCopy.m_size, m_array);
}



// Destructor
template<typename T>
Self_Vector<T>::~Self_Vector()
{
	delete[] m_array;
}



// Operator-Overloads
template<typename T>
T& Self_Vector<T>::operator[](const std::size_t index)
{
	assert(index < m_size && index >= 0 && "Out of bounds");
	return m_array[index];
}

template<class T>
void Self_Vector<T>::operator=(const Self_Vector<T>& toCopy)
{
	m_capacity = toCopy.m_capacity;
	m_size = toCopy.m_size;

	m_array = new T[toCopy.m_capacity];
	std::copy(toCopy.m_array, toCopy.m_array + toCopy.m_size, m_array);
}




// Member-Functions
template<typename T>
void Self_Vector<T>::pushback(const T& elem)
{
	// If the array capacity would be smaller than the current size + the new element, create a bigger array
	if (m_capacity < m_size + 1)
	{
		T* tempArray = m_array;

		// Increase the capacity
		m_capacity += 4;

		// Create a new array with a bigger capacity
		m_array = new T[m_capacity];

		std::copy(tempArray, tempArray + m_size, m_array);

		delete[] tempArray;
	}

	// Add an element to the end
	++m_size;
	m_array[m_size - 1] = elem;
}

template<typename T>
void Self_Vector<T>::pushback(T&& elem)
{
	// If the array capacity would be smaller than the current size + the new element, create a bigger array
	if (m_capacity < m_size + 1)
	{
		T* tempArray = m_array;

		// Increase the capacity
		m_capacity += 4;

		// Create a new array with a bigger capacity
		m_array = new T[m_capacity];

		std::copy(tempArray, tempArray + m_size, m_array);

		delete[] tempArray;
	}

	// Add an element to the end
	++m_size;
	m_array[m_size - 1] = elem;
}


template<typename T>
void Self_Vector<T>::popback()
{
	if(m_size > 0)
		--m_size;

	// if m_size is 0, there is nothing to pop
}


template<typename T>
void Self_Vector<T>::clear()
{
	if (m_capacity == 0 && m_array == nullptr)
		return;


	m_capacity = 0;
	m_size = 0;

	delete[] m_array;
	m_array = nullptr;
}

template<typename T>
void Self_Vector<T>::removeAt(const std::size_t index)
{
	assert(index >= 0 && index < m_size && "Out of bounds");

	// Copy all but the index to remove into an array
	T* resArray = new T[m_capacity];

	// Before the index
	for (std::size_t i = 0; i < index; i++)
	{
		resArray[i] = m_array[i];
	}

	// After the index
	for (std::size_t i = index; i < m_size - 1; i++)
	{
		resArray[i] = m_array[i + 1];
	}

	delete[] m_array;
	--m_size;                  // One element removed, so decrease size by 1

	m_array = resArray;
}


template <typename T>
void Self_Vector<T>::sort(bool (*func)(T& first, T& second))
{
	if (m_size <= 1)
		return;

	std::sort(m_array, m_array + m_size, func);
}


template<class T>
void Self_Vector<T>::reverse()
{
	if (m_size <= 1)
		return;

	std::reverse(m_array, m_array + m_size);
}

template<class T>
void Self_Vector<T>::swap(const std::size_t first, const std::size_t second)
{
	assert(first >= 0 && first < m_size && second >= 0 && second < m_size);

	if (first == second)
		return;

	T temp = m_array[first];
	m_array[first] = m_array[second];
	m_array[second] = temp;
}



template<class T>
bool Self_Vector<T>::search(T* arr, std::size_t first, std::size_t last, T element) const
{
	std::size_t mid = (first + last) / 2;

	if (element == arr[mid])
		return true;

	if (last >= 1)
	{
		if (first >= m_size - 1) 
			return false;

		if (element < arr[mid])
			return search(arr, first, mid - 1, element);

		return search(arr, mid + 1, last, element);
	}
	else
		return false;
}

template<>
bool Self_Vector<char>::search(char* arr, std::size_t first, std::size_t last, char element) const
{
	// Specialisation which converts char into ints and then compares the int values of the char's instead of the char's

	auto elementAsInt = static_cast<int>(element);

	std::size_t mid = (first + last) / 2;

	if (elementAsInt == static_cast<std::size_t>(arr[mid]))
		return true;

	if (last >= 1)
	{
		if (first >= m_size - 1)
			return false;

		if (elementAsInt < static_cast<std::size_t>(arr[mid]))
			return search(arr, first, static_cast<std::size_t>(mid) - 1, elementAsInt);

		return search(arr, static_cast<std::size_t>(mid) + 1, last, elementAsInt);
	}
	else
		return false;
}

template<>
bool Self_Vector<std::string>::search(std::string* arr, std::size_t first, std::size_t last, std::string element) const
{
	for (std::size_t i = 0; i < m_size; i++)
	{
		if (element == m_array[i])
			return true;
	}

	return false;
}



template<typename T>
bool Self_Vector<T>::contains(T& elem) const
{
	if (m_size <= 0)
		return false;

	T* arr = new T[m_size];

	std::copy(m_array, m_array + m_size, arr);

	std::sort(arr, arr + m_size);

	return search(arr, 0, m_size - 1, elem);
}



template<class T>
void Self_Vector<T>::insertAt(const std::size_t index, const T& elem)
{
	assert(index >= 0 && index <= m_size && "Out of bounds");

	// Pushback instead of insert if you want to add an item to the end
	if (index == m_size)
	{
		pushback(elem);
		return;
	}

	T* tempArray = new T[m_size + 1];

	// Before the index
	for (std::size_t i = 0; i < index; i++)
	{
		tempArray[i] = m_array[i];
	}

	// Element to insert at index
	tempArray[index] = elem;

	// After the index
	for (std::size_t i = index; i < m_size; i++)
	{
		tempArray[i + 1] = m_array[i];
	}

	++m_size;
	++m_capacity;

	delete[] m_array;
	m_array = tempArray;
}

template<class T>
void Self_Vector<T>::insertAt(const std::size_t index, T&& elem)
{
	assert(index >= 0 && index <= m_size && "Out of bounds");

	// Pushback instead of insert if you want to add an item to the end
	if (index == m_size)
	{
		pushback(elem);
		return;
	}

	T* tempArray = new T[m_size + 1];

	// Before the index
	for (std::size_t i = 0; i < index; i++)
	{
		tempArray[i] = m_array[i];
	}

	// Element to insert at index
	tempArray[index] = elem;

	// After the index
	for (std::size_t i = index; i < m_size; i++)
	{
		tempArray[i + 1] = m_array[i];
	}

	++m_size;
	++m_capacity;

	delete[] m_array;
	m_array = tempArray;
}



template<typename T>
T* Self_Vector<T>::begin() const
{
	return m_array;
}

template<typename T>
T* Self_Vector<T>::end() const
{
	return m_array + m_size;
}

template<typename T>
std::size_t Self_Vector<T>::size() const
{
	return m_size;
}


template<typename T>
std::size_t Self_Vector<T>::capacity() const
{
	return m_capacity;
}