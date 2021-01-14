#include <iostream>
#include <vector>
#include <numeric>

using TLLVec = std::vector<long long>;

class Fibonacci
{
public:
	Fibonacci();
	TLLVec getFibsTo(long long);               //Gets all fibonacci numbers to a given max into a vector
	TLLVec filterAllEvenNumbers(TLLVec);      //Removes all odd numbers from a vec
	long long sumVec(TLLVec);                  //Sums all values of a vector up
private:
};