#include <unordered_map>
#include <iostream>
#include <vector>


void printRightPairs(const std::string& inputString) {

	std::unordered_map<char, char> uMap;

	uMap.insert(std::pair<char, char>('A', 'T'));
	uMap.insert(std::pair<char, char>('T', 'A'));
	uMap.insert(std::pair<char, char>('G', 'C'));
	uMap.insert(std::pair<char, char>('C', 'G'));

	std::vector<char> charVec(inputString.begin(), inputString.end());

	for (int i = 0; i < charVec.size(); i++) {

		std::cout << uMap[charVec[i]];
	}

	std::cout << std::endl;
}


int main() 
{
	std::string userInput;
	std::cin >> userInput;

	printRightPairs(userInput);

	int eND;
	std::cin >> eND;
	return 0;
}
