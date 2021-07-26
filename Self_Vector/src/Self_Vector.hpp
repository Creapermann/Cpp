#pragma once

#include <array>
#include <initializer_list>
#include <string>
#include <functional>
#include <algorithm>


template<class T>
class Self_Vector final
{
private:
	std::size_t m_size{};
	std::size_t m_capacity{};
	T* m_array;

	bool binarySearch(T* arr, std::size_t first, std::size_t last, T element);
	bool stringSearch(std::string str);

public:
	// Constructors
	Self_Vector() = default;
	Self_Vector(std::initializer_list<T> list);
	Self_Vector(std::size_t cap);



	// Destructor
	~Self_Vector();



	// Member-Functions
	void pushback(T element);
	void popback();
	void clear();
	void removeAt(std::size_t index);
	void sort(bool (*func)(T& first, T& second) = [](T& a, T& b) { return a < b; });

	bool contains(T element);


	T* begin();
	T* end();

	std::size_t size();
	std::size_t capacity();


		
	// Operator-Overloads
	T& operator[](std::size_t index);
};


// Class definition
#include "Self_Vector.txx"