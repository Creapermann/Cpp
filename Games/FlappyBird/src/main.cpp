//Just a casual Flappy Bird game

#include "flappyBird.hpp"




int main() {

	//Let the user type in "rs" to start the game again
	bool playAgain = true;
	while (playAgain) {
		playAgain = false;
		system("CLS");
		FlappyBird fb = FlappyBird();
		system("CLS");
		std::cout << "Type 'rs' to restart the game!" << std::endl;
		std::string r;
		std::cin >> r;
		if (r == "rs" || r == "RS" || r == "Rs")
			playAgain = true;
	}

	std::cin.get();
	return 0;
}