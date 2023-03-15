#

#include "multiples.hpp"

Multiples::Multiples() {};

TIntVec Multiples::getMltpTo(int n, TIntVec checkers) {
	TIntVec foundNums;

	for (int k = 1; k < n; k++) {
		if (k % 3 == 0 || k % 5 == 0)
			foundNums.push_back(k);
	}

	return foundNums;
}

int Multiples::sumVec(TIntVec mainVec) {
	int res = std::accumulate(mainVec.begin(), mainVec.end(), 0);

	return res;
}