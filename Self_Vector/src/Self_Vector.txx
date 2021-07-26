#include "Self_Vector.hpp"

#include <cassert>
#include <algorithm>


// Constructors
template<typename T>
Self_Vector<T>::Self_Vector(std::initializer_list<T> list)
	: m_capacity{ list.size() }, m_size{ list.size() }
{
	m_array = new T[m_capacity];

	int count{ 0 };
	for (T i : list)
	{
		m_array[count] = i;
		++count;
	}
}

template<typename T>
Self_Vector<T>::Self_Vector(std::size_t cap)
	: m_capacity{ cap }
{
	m_array = new T[m_capacity];
}



// Destructor
template<typename T>
Self_Vector<T>::~Self_Vector()
{
	delete[] m_array;
}



// Operator-Overloads
template<typename T>
T& Self_Vector<T>::operator[](std::size_t index)
{
	assert(index < m_size && index >= 0 && "Out of bounds");
	return m_array[index];
}

template<class T>
void Self_Vector<T>::operator=(Self_Vector<T>& toCopy)
{
	m_capacity = toCopy.m_capacity;
	m_size = toCopy.m_size;

	m_array = new T[toCopy.m_capacity];
	memcpy(m_array, toCopy.m_array, sizeof(T) * toCopy.m_size);
}




// Member-Functions
template<typename T>
void Self_Vector<T>::pushback(T elem)
{
	// If the array capacity would be smaller than the current siez + the new object, create a bigger array
	if (m_capacity < m_size + 1)
	{
		T* tempArray = m_array;

		// Increase the capacity
		m_capacity += 4;

		// Create a new array with a bigger capacity
		m_array = new T[m_capacity];

		// Fill the new (bigger) array with the values from the old array
		for (int i = 0; i < m_size; i++)
		{
			m_array[i] = tempArray[i];
		}

		delete[] tempArray;
	}

	// Add an element to the end
	++m_size;
	m_array[m_size - 1] = elem;
}


template<typename T>
void Self_Vector<T>::popback()
{
	--m_size;
}


template<typename T>
void Self_Vector<T>::clear()
{
	m_capacity = 0;
	m_size = 0;

	delete[] m_array;
}

template<typename T>
void Self_Vector<T>::removeAt(std::size_t index)
{
	assert(index >= 0 && index < m_size && "Out of bounds");

	// Copy all but the index to remove into an array
	T* resArray = new T[m_capacity];

	// Before the index
	for (int i = 0; i < index; i++)
	{
		resArray[i] = m_array[i];
	}

	// After the index
	for (int i = index; i < m_size - 1; i++)
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
	std::sort(m_array, m_array + m_size, func);
}


template<class T>
void Self_Vector<T>::reverse()
{
	std::reverse(m_array, m_array + m_size);
}


template<class T>
bool Self_Vector<T>::binarySearch(T* arr, std::size_t first, std::size_t last, T element)
{
	std::size_t mid = (first + last) / 2;

	if (element == arr[mid])
		return true;

	if (last >= 1)
	{
		if (first >= m_size - 1) 
			return false;

		if (element < arr[mid])
			return binarySearch(arr, first, mid - 1, element);

		return binarySearch(arr, mid + 1, last, element);
	}
	else
		return false;
}

template<typename T>
bool Self_Vector<T>::stringSearch(std::string str)
{
	for (int i = 0; i < m_size; i++)
	{
		if (str == m_array[i])
			return true;
	}

	return false;
}


template<typename T>
bool Self_Vector<T>::contains(T elem)
{
	T* arr = new T[m_size];

	for (int i = 0; i < m_size; i++)
	{
		arr[i] = m_array[i];
	}

	std::sort(arr, arr + m_size);

	return binarySearch(arr, 0, m_size - 1, elem);
}


template<>
bool Self_Vector<std::string>::contains(std::string elem)
{
	return stringSearch(elem);
}


template<class T>
void Self_Vector<T>::insert(std::size_t index, T elem)
{
	T* tempArray = new T[m_size + 1];
	for (int i = 0; i < index; i++)
	{
		tempArray[i] = m_array[i];
	}

	tempArray[index] = elem;

	for (int i = index; i < m_size; i++)
	{
		tempArray[i + 1] = m_array[i];
	}

	delete[] m_array;
	m_array = tempArray;
}



template<typename T>
T* Self_Vector<T>::begin()
{
	if (!m_array)
	{
		return nullptr;
	}

	return m_array;
}

template<typename T>
T* Self_Vector<T>::end()
{
	if (!m_array)
	{
		return nullptr;
	}

	return m_array + m_size;
}

template<typename T>
std::size_t Self_Vector<T>::size()
{
	return m_size;
}


template<typename T>
std::size_t Self_Vector<T>::capacity()
{
	return m_capacity;
}