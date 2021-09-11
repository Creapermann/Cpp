#include <iostream>

#


int fac(int n) {

	if (n <= 0) {
		return 0;						  //base-case
	}
	else {
		return n + fac(n - 1);            //recursive-case
	}
}


int main() {

	std::cout << fac(3) << std::endl;

	std::cin.get();
	return 0;
}