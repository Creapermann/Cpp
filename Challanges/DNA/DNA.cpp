#include <string>
#include <vector>
#include <iostream>
#include <set>


template <typename T>  void uniqueInOrder(const std::vector<T>& iterable) {

	std::vector<T> endVec;

	for (auto i = 0; i < iterable.size(); i++) {
		if (i == 0) {
			endVec.push_back(iterable[i]);
		}
		else if (iterable[i] != iterable[i - 1]) {
			endVec.push_back(iterable[i]);
		}
	}

	for (auto c : endVec) {
		std::cout << c;
	}


}
std::vector<char> uniqueInOrder(const std::string& iterable) {
	std::vector<char> splitInCharsVec(iterable.begin(), iterable.end());

	return splitInCharsVec;
}

int main() {
	std::string input;
	std::cin >> input;

	uniqueInOrder(uniqueInOrder(input));

	int eND;
	std::cin >> eND;
	return 0;
}