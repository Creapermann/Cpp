#include <iostream>
#include <vector>

#include "bubbleSort.hpp"


//Constructors
bubbleSort::bubbleSort(const TIntVec& mainVec) {

	TIntVec resVec = sortVec(mainVec);
	printResVec(resVec);
}



TIntVec bubbleSort::sortVec(const TIntVec& mV) {
	auto mVCopy = mV;


	for (int i = 0; i < mVCopy.size() - 1; i++) {            //checks for every element of the vector, if the following is bigger, if yes they swap
		for (int j = i + 1; j < mVCopy.size(); j++) {
			int temp;
			if (mVCopy[i] > mVCopy[j]) {
				temp = mVCopy[i];
				mVCopy[i] = mVCopy[j];
				mVCopy[j] = temp;
			}
		}
	}

	return mVCopy;
}


void bubbleSort::printResVec(const TIntVec& sortedMV) {

	for (auto o : sortedMV) {
		std::cout << o << " ";
	}
	std::cout << std::endl;
}
