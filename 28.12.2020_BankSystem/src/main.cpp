#include <iostream>

#include "banking.hpp"

int main() { 
	
	Banking b = Banking();
	b.menu();

	std::cin.get();
	return 0; 
}