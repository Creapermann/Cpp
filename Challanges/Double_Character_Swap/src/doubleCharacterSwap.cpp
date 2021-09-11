

#include "doubleCharacterSwap.hpp"


DoubleCharacterSwap::DoubleCharacterSwap(std::string mainString, char a, char b) {
	print(swaper(mainString, a, b));
}


std::string DoubleCharacterSwap::swaper(std::string mainString, char a, char b) {
	
	for (int i = 0; i < mainString.size(); i++) {
		if (mainString[i] == a)
			mainString[i] = b;
		
		else if (mainString[i] == b)
			mainString[i] = a;
	}

	return mainString;
}


void DoubleCharacterSwap::print(std::string resString) {
	std::cout << resString << std::endl;
}