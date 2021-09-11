#pragma once
#include <vector>

using TIntVec = std::vector<int>;


class SelectionSort
{
public:
	SelectionSort(TIntVec);
	TIntVec sort(const TIntVec &);
	void print(const TIntVec &);

private:

};
