#include <iostream>

#include <vector>
#include <unordered_set>

using TIntVec = std::vector<int>;



class FindOddInt
{
public:
	FindOddInt(const TIntVec&);
	std::unordered_set<int> find(const TIntVec&);
	void print(const std::unordered_set<int>&);


private:

};