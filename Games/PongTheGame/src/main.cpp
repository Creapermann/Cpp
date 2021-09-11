//Just a casual pong game

#include "pong.hpp"


int main() {

	//Let the user type in "rs" to start the game again
	bool playAgain = true;
	while (playAgain) {
		playAgain = false;
		system("CLS");
		Pong fb = Pong();
		std::cout << "\nType 'rs' to restart the game!" << std::endl;
		std::string r;
		std::cin >> r;
		if (r == "rs" || r == "RS" || r == "Rs")
			playAgain = true;
	}

	std::cin.get();
	return 0;
}