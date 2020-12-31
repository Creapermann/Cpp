#include <iostream>

#include "selectionSort.hpp"


int main() {

	TIntVec mainVec = { 4, 1, 7, 19, 21, 36, 11, 99, 1, 7, 4, 2 };

	SelectionSort ss(mainVec);

	std::cin.get();
	return 0;
}