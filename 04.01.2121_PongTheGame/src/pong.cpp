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
	fieldHeight = 15;
	fieldWidth = 40;

	ballPosX = (fieldWidth / 2);
	ballPosY = (fieldHeight / 2);


	playerLeftX = 1;
	playerLeftY = (fieldHeight / 2) -1 ;
	playerRightX = (fieldWidth - 2);
	playerRightY = (fieldHeight / 2) - 1;

	playerHeight = 3;

	score = 0;

	scorePosX = (fieldWidth / 2) - 4;
	scorePosY = 2;

	gameOver = false;


	//Ball-Start Dir
	resetBall();
}



void Pong::draw() {

	system("CLS");

	//Upper row
	for (int i = 0; i < fieldWidth + 2; i++)
		std::cout << "#";
	std::cout << std::endl;


	//Mainpart
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
						if (i == scorePosY && k == scorePosX + j) {
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
									std::cout << score;
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


	//Lower row
	for (int i = 0; i < fieldWidth + 2; i++)
		std::cout << "#";
	std::cout << std::endl;

}



void Pong::input() {
	//Player Left Movement
	if (_kbhit()) {
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
	if (_kbhit()) {
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

		PlayerLeft = player::STOP;
		PlayerRight = player::STOP;
	}



	//Ball-Movement
	if (ballDir == ball::LEFT)
		ballPosX--;
	else if (ballDir == ball::RIGHT)
		ballPosX++;

	


	//Ball-Collision

	if (ballPosX >= fieldWidth || ballPosX <= 0) {          //Side-Border collision (Game lose)
		score++;
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

	//Upper-Border
	if (int(ballPosY) <= 0) {
		std::uniform_real_distribution<double> rndmBallDownAngle(0.2, 0.5);
		ballAngle = rndmBallDownAngle(rndmGen);
	}

	//Lower-Border
	if (int(ballPosY) >= (fieldHeight - 1)) {
		std::uniform_real_distribution<double> rndmBallDownAngle(-0.5, -0.2);
		ballAngle = rndmBallDownAngle(rndmGen);
	}


	//Set Ball Angle
	ballPosY += ballAngle;


	//Won-Game
	if (score >= 10)
		gameOver = true;

	//Waiting
	Sleep(20);
}



void Pong::resetBall() {

	ballPosX = (fieldWidth / 2);
	ballPosY = (fieldHeight / 2);

	
	std::uniform_int_distribution<int> rndmBallSpawn(0, 10);
	std::uniform_int_distribution<int> rndmStartAngleChooser(0, 10);

	std::uniform_real_distribution<double> rndmBallAngle1(-0.3, -0.1);
	std::uniform_real_distribution<double> rndmBallAngle2(0.1, 0.3);

	if(rndmStartAngleChooser(rndmGen) >= 5)
		ballAngle = rndmBallAngle1(rndmGen);
	else
		ballAngle = rndmBallAngle2(rndmGen);

	if (rndmBallSpawn(rndmGen) >= 5)
		ballDir = ball::LEFT;
	else
		ballDir = ball::RIGHT;
}