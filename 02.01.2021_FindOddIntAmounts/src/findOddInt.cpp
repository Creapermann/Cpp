#include "findOddInt.hpp"

#include <algorithm>



FindOddInt::FindOddInt(const TIntVec &mainVec) {
	print(find(mainVec));
}


std::set<int> FindOddInt::find(const TIntVec& mainVec) {

	TIntVec oddAmountOfVec;

	for (int i = 0; i < mainVec.size(); i++) {
		int temp = mainVec[i];

		int a = std::count_if(mainVec.begin(), mainVec.end(), [i = i,resVec = mainVec](auto& elm) {return elm == resVec[i]; });
		if (a % 2 != 0) {
			oddAmountOfVec.emplace_back(mainVec[i]);
		}
	}

	//Remove duplicates by a conversion to a set
	std::set<int> tempS(oddAmountOfVec.begin(), oddAmountOfVec.end());

	return tempS;
}


void FindOddInt::print(const std::set<int>& resSet) {
	for (auto o : resSet) {
		std::cout << o << " ";
	}
	std::cout << std::endl;
}