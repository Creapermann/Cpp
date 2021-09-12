#include <iostream>
#include <vector>
#include <numeric>

using TIntVec = std::vector<int>;

class Multiples
{
public:
	Multiples();
	TIntVec getMltpTo(int, TIntVec);
	int sumVec(TIntVec);
private:
};