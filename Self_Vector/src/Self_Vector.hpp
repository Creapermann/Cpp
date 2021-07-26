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
	T* m_array{ nullptr };

	bool binarySearch(T* arr, std::size_t first, std::size_t last, T element);
	bool stringSearch(std::string str);

public:
	// Constructors
	Self_Vector() = default;
	Self_Vector(std::initializer_list<T> list);
	explicit Self_Vector(std::size_t cap);

	Self_Vector(Self_Vector& toCopy) = delete;


	// Destructor
	~Self_Vector();



	// Member-Functions
	void pushback(T elem);
	void popback();
	void clear();
	void removeAt(std::size_t index);
	void sort(bool (*func)(T& first, T& second) = [](T& a, T& b) { return a < b; });
	void reverse();
	void insert(std::size_t index, T elem);

	bool contains(T elem);


	T* begin();
	T* end();

	std::size_t size();
	std::size_t capacity();


		
	// Operator-Overloads
	T& operator[](std::size_t index);

	void operator=(Self_Vector<T>& toCopy);
};


// Class definition
#include "Self_Vector.txx"