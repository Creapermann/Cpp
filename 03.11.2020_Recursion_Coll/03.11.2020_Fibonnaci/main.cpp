#include <iostream>

#


int fib(int cnt, int term1, int term2) {
	
	std::cout << term1 << " ";

	if (cnt <= 0) {											 //base-case
		std::cout << term2 << " ";
		return term1 + term2;
	}
	else {                                                   //recursive-case
		return fib(cnt - 1, term2, term1 + term2);
	}
}


int main() {

	std::cout << fib(5, 0, 1) << std::endl;


	std::cin.get();
	return 0;
}