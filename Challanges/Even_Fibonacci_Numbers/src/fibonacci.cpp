#include "fibonacci.hpp"

Fibonacci::Fibonacci() {};

TLLVec Fibonacci::getFibsTo(long long n) {
	TLLVec mainVec = { 1, 2 };

	while (true) {
		long long r = mainVec[mainVec.size() - 1] + mainVec[mainVec.size() - 2];    //adds the last 2 values together to create a new one

		if (r <= n)
			mainVec.emplace_back(r);           //if the values is smaller than the given max add it
		else
			break;                             //else exit the while loop
	}

	return mainVec;
}

TLLVec Fibonacci::filterAllEvenNumbers(TLLVec mainVec) {
	auto const a = std::remove_if(mainVec.begin(), mainVec.end(), [](long long x) {return x % 2 != 0; });    //moves all odd numbers to the end
	mainVec.erase(a, mainVec.end());            //removes all odd numbers
	return mainVec;
}

long long Fibonacci::sumVec(TLLVec mainVec) {
	long long res = std::accumulate(mainVec.begin(), mainVec.end(), 0);             //Adds all the numbers in the vector together

	return res;
}