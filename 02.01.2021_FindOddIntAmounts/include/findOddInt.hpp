#include <iostream>

#include <vector>
#include <set>

using TIntVec = std::vector<int>;



class FindOddInt
{
public:
	FindOddInt(const TIntVec&);
	std::set<int> find(const TIntVec&);
	void print(const std::set<int>&);

private:

};