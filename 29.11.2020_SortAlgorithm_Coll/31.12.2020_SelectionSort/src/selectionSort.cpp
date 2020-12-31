#include <iostream>

#include "selectionSort.hpp"


SelectionSort::SelectionSort(TIntVec mainVec) {
	
	print(sort(mainVec));

}




TIntVec SelectionSort::sort(const TIntVec &mainVec) {
	TIntVec resVec = mainVec;

	for (int i = 0; i < resVec.size() - 1; i++) {
		for (int k = 0 + i; k < resVec.size(); k++) {

			int currentItem = k;
			int lowestItem = i;

			if (resVec[currentItem] < resVec[lowestItem]) {
				int temp = resVec[currentItem];
				resVec[currentItem] = resVec[lowestItem];
				resVec[lowestItem] = temp;
			}
		}
	}

	return resVec;
}



void SelectionSort::print(const TIntVec &resVec){

	for (auto i : resVec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}