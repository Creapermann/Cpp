#pragma once
#include <vector>
#include <optional>


using TIntVec = std::vector<int>;

using TIntPair = std::pair<int, int>;
using TOptIntPair = std::optional<std::pair<int, int>>;
using TOptIntPairVec = std::vector<TOptIntPair>;

using TIntPairVec = std::vector<std::pair<int, int>>;

//Class
class diffOfTwo {
public:
	//Constructor
	diffOfTwo(const TIntVec&);

private:
	TOptIntPairVec initPairVec(const TIntVec&);					//inits the "coupleVec" vector
	TOptIntPairVec eraseUnnesecary(const TOptIntPairVec&);      //erases the the empty OptionalEmptyPairs from the vector
	TIntPairVec convOptVecToNonOptVec(const TOptIntPairVec&);   //converts the OptionalIntPairVector to a IntPairVector to be able to acess the elements of the Int-Pair
	void printRes(const TOptIntPairVec&);                       //prints the result vector
};