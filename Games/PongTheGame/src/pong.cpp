#include <ctime>
#include <random>
#include <conio.h>

#include "pong.hpp"


std::default_random_engine rndmGen(time(0));


Pong::Pong() {
	init();
	//Game Loop
	while (gameOver != true) {
		draw();
		input();
		logic();
	}
}



void Pong::init() {
	
	//Field
	fieldHeight = 15;
	fieldWidth = 40;

	//Ball
	ballPosX = (fieldWidth / 2);
	ballPosY = (fieldHeight / 2);

	//Player
	playerLeftX = 1;
	playerLeftY = (fieldHeight / 2) -1 ;
	playerRightX = (fieldWidth - 2);
	playerRightY = (fieldHeight / 2) - 1;
	playerHeight = 3;

	//Scores
	scorePlayerLeft = 0;
	scorePlayerRight = 0;

	scorePlayerLeftPosX = (fieldWidth - 5 - 8);
	scorePlayerLeftPosY = 2;
	scorePlayerRightPosX = 5;
	scorePlayerRightPosY = 2;


	gameOver = false;


	//Ball-Start Dir
	resetBall();
}



void Pong::draw() {

	system("CLS");

	//Upper Border
	for (int i = 0; i < fieldWidth + 2; i++)
		std::cout << "#";
	std::cout << std::endl;

	
	for (int i = 0; i < fieldHeight; i++) {
		for (int k = -1; k < fieldWidth + 1; k++) {           //-1 and +1 are so the first free slot stays index 0 (from left to right) and not 1
			if (k == -1 || k == fieldWidth)                   //For the border on the left and the right
				std::cout << "#";
			else if (k == ballPosX && i == int(ballPosY))          //For the Ball
				std::cout << "O";
			else {
				//For the Player draw
				bool isPlayer = false;
				for (int j = 0; j < playerHeight; j++) {
					if (k == playerLeftX && (i == playerLeftY + j) || k == playerRightX && i == (playerRightY + j)) {
						isPlayer = true;
						std::cout << "|";
					} 
				}

				//For the Score draw
				bool isScore = false;
				if (isPlayer != true) {
					for (int j = 0; j < 8; j++) {
						//Player Left Score
						if (i == scorePlayerLeftPosY && k == scorePlayerLeftPosX + j) {
							isScore = true;
							switch (j) {
								case 0:
									std::cout << "S";
									break;
								case 1:
									std::cout << "c";
									break;
								case 2:
									std::cout << "o";
									break;
								case 3:
									std::cout << "r";
									break;
								case 4:
									std::cout << "e";
									break;
								case 5:
									std::cout << ":";
									break;
								case 6:
									std::cout << " ";
									break;
								case 7:
									std::cout << scorePlayerLeft;
									break;
							}
						}
						
						//Player Right Score
						if (i == scorePlayerRightPosY && k == scorePlayerRightPosX + j) {
							isScore = true;
							switch (j) {
							case 0:
								std::cout << "S";
								break;
							case 1:
								std::cout << "c";
								break;
							case 2:
								std::cout << "o";
								break;
							case 3:
								std::cout << "r";
								break;
							case 4:
								std::cout << "e";
								break;
							case 5:
								std::cout << ":";
								break;
							case 6:
								std::cout << " ";
								break;
							case 7:
								std::cout << scorePlayerRight;
								break;
							}
						}
					}
				}

				//For the empty field draw
				if (isPlayer != true && isScore != true)     
					std::cout << " "; 
			}
		}
		std::cout << std::endl;
	}

	//Lower Border
	for (int i = 0; i < fieldWidth + 2; i++)
		std::cout << "#";
	std::cout << std::endl;

}



void Pong::input() {
	//Player Left Movement
	if (_kbhit()) {                        //If the keyboard is it
		char c = _getch();
		switch (c) {
			//Player Left
			case 'w':
				PlayerLeft = player::UP;
				break;
			case 's':
				PlayerLeft = player::DOWN;
				break;
		}
	}
	//Player Right Movement
	if (_kbhit()) {                        //If the keyboard is it
		char a = _getch();
		switch (a) {
				//Player Right
			case 72:
				PlayerRight = player::UP;
				break;
			case 80:
				PlayerRight = player::DOWN;
				break;
		}
	}
}



void Pong::logic() {
	if (true /*closing purpose*/) {
		//Player-Movement
		if (PlayerLeft == player::UP && playerLeftY - 1 >= 0)
			playerLeftY--;

		else if (PlayerLeft == player::DOWN && playerLeftY + playerHeight + 1 <= fieldHeight)
			playerLeftY++;


		if (PlayerRight == player::UP && playerRightY - 1 >= 0)
			playerRightY--;

		else if (PlayerRight == player::DOWN && playerRightY + playerHeight + 1 <= fieldHeight)
			playerRightY++;

		//Direction is set to STOP after it moves one
		PlayerLeft = player::STOP;
		PlayerRight = player::STOP;
	}



	//Ball-Movement
	if (ballDir == ball::LEFT)
		ballPosX--;
	else if (ballDir == ball::RIGHT)
		ballPosX++;



	//Side-Border collision -> Game lose, adds the score up to one and resets the ball to the middle again
	if (ballPosX <= 0) {
		scorePlayerRight++;
		resetBall();
	}
	else if (ballPosX >= fieldWidth) {
		scorePlayerLeft++;
		resetBall();
	}

	for (int i = 0; i < playerHeight; i++) {                //Player collsion
		//Left Player
		if (ballPosX == playerLeftX && int(ballPosY) == (playerLeftY + i)) {
			ballDir = ball::RIGHT;
		}

		//Right Player
		if (ballPosX == playerRightX && int(ballPosY) == (playerRightY + i)) {
			ballDir = ball::LEFT;

		}
	}


	//Changes the fly angle if the ball collides with the Upper-Border
	if (int(ballPosY) <= 0) {
		std::uniform_real_distribution<double> rndmBallDownAngle(0.2, 0.5);
		ballAngle = rndmBallDownAngle(rndmGen);
	}

	//Changes the fly angle if the ball collides with the Bottom-Border
	if (int(ballPosY) >= (fieldHeight - 1)) {
		std::uniform_real_distribution<double> rndmBallDownAngle(-0.5, -0.2);
		ballAngle = rndmBallDownAngle(rndmGen);
	}


	//Set Ball Angle
	ballPosY += ballAngle;    //Applys the angle to the ball


	//Won-Game
	if (scorePlayerRight >= 10){
		gameOver = true;
		system("CLS");
		std::cout << "Player Right has won!" << std::endl;
	}
	else if (scorePlayerLeft >= 10) {
		gameOver = true;
		system("CLS");
		std::cout << "Player Left has won!" << std::endl;
	}
	//Waiting
	Sleep(15);    //How fast the screen refreshs
}


//Resets the Ball to the position (0|0) and adds a random Angle and a random Direction to it 
void Pong::resetBall() {

	//Sets the ball position to (0|0)
	ballPosX = (fieldWidth / 2);
	ballPosY = (fieldHeight / 2);


	//chooses a angle for the start ball, 2 random angles are created so that the ball Angle cant be to flat
	std::uniform_int_distribution<int> rndmStartAngleChooser(0, 10);
	std::uniform_real_distribution<double> rndmBallAngle1(-0.3, -0.1);
	std::uniform_real_distribution<double> rndmBallAngle2(0.1, 0.3);

	if (rndmStartAngleChooser(rndmGen) >= 5)
		ballAngle = rndmBallAngle1(rndmGen);
	else
		ballAngle = rndmBallAngle2(rndmGen);


	//For the random start direction (LEFT or RIGHT)
	std::uniform_int_distribution<int> rndmBallDir(0, 10);
	
	if (rndmBallDir(rndmGen) >= 5)
		ballDir = ball::LEFT;
	else
		ballDir = ball::RIGHT;
}