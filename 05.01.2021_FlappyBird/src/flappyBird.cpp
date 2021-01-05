#include <conio.h>

#include "flappyBird.hpp"


int o = 0;


FlappyBird::FlappyBird() {
	bool rdyToStart = false;
	while (rdyToStart != true) {
		std::cout << "Type in START to start the game!" << std::endl;
		std::string s;
		std::cin >> s;
		if (s == "start" || s == "START" || s == "Start" ||s == "s")
			rdyToStart = true;
		
		system("CLS");
	}

	init();
	
	while (gameOver != true) {
		draw();
		input();
		logic();
	}
}




void FlappyBird::init() {
	fieldHeight = 20;
	fieldWidth = 80;

	playerX = 2;
	playerY = (fieldHeight / 2);

	//To place the first 5 Tubes
	prevTubeX = 20;
	for (int i = 0; i < 5; i++) {
		Tube temp = Tube(fieldHeight, prevTubeX, 3);
		tubeVec.emplace_back(temp);
		prevTubeX += 20;
	}

}


void FlappyBird::draw() {

	system("CLS");

	//Upper field border
	for (int i = -1; i < (fieldWidth + 1); i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i < fieldHeight; i++) {
		for (int k = -1; k < fieldWidth + 1; k++) {
			if (k == -1 || k == fieldWidth)               //left / right border
				std::cout << "#";
			else if (k == playerX && i == playerY)        //Player
				std::cout << "B";
			else {

				bool isTube = false;
				for (int j = 0; j < tubeVec.size(); j++) {
					for (int h = 0; h < tubeVec[j].tubeSize1; h++) {
						if (i == tubeVec[j].tubeY1 + h && k == tubeVec[j].tubeX1) {      //Upper Tube
							isTube = true;
							std::cout << "0";
						}
						if (i == tubeVec[j].tubeY1 + h && k == tubeVec[j].tubeX1Extension) {      //Upper Tube Extension (to make it x2)
							isTube = true;
							std::cout << "0";
						}
					}

					for (int h = 0; h < tubeVec[j].tubeSize2; h++) {
						if (i == tubeVec[j].tubeY2 - h && k == tubeVec[j].tubeX2) {      //Lower Tube
							isTube = true;
							std::cout << "0";
						}
						if (i == tubeVec[j].tubeY2 - h && k == tubeVec[j].tubeX2Extension) {      //Lower Tube Extension (to make it x2)
							isTube = true;
							std::cout << "0";
						}
					}
				}


				if(isTube != true)          //Empty field
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}


	//Lower field border
	for (int i = -1; i < (fieldWidth + 1); i++)
		std::cout << "#";
	std::cout << std::endl;

	//Score
	std::cout << "Score: " << score << std::endl;
}



void FlappyBird::input() {

	//Player input
	if (_kbhit()) {              //checks if any keyboard button was pressed
		char c = _getch();
		switch (c) {
		//Player Left
		case 32:                 //ASCCI 32 == SPACEBAR
			playerDir = player::UP;
			break;
		}
	}
}



void FlappyBird::logic() {

	//Player movement
	if (playerDir == player::UP)
		playerY--;
	else if (playerDir == player::DOWN)
		playerY++;

	//Player moves down every frame
	playerDir = player::DOWN;
	//Player moves forward every frame
	playerX++;




	//Top-Bottom Wall Collider
	if (playerY >= fieldHeight)
		gameOver = true;
	else if(playerY < 0)
		gameOver = true;


	//Tube Colliders
	for (int j = 0; j < tubeVec.size(); j++) {
		for (int h = 0; h < tubeVec[j].tubeSize1; h++) {
			if (playerY == tubeVec[j].tubeY1 + h && playerX == tubeVec[j].tubeX1) {      //Upper Tube
				gameOver = true;
			}
		}

		for (int h = 0; h < tubeVec[j].tubeSize2; h++) {
			if (playerY == tubeVec[j].tubeY2 - h && playerX == tubeVec[j].tubeX2) {      //Lower Tube
				gameOver = true;
			}
		}
	}
	//Tube Extensions have no collider because the game would be to hard



	//Add up score and Manage Tube Vec
	for (int j = 0; j < tubeVec.size(); j++) {
		if (playerX == tubeVec[j].tubeX1 + 2) {
			score++;                                //Adds score by one


			//Delete first tube
			tubeVec.erase(tubeVec.begin());

			//Add a new
			Tube temp = Tube(fieldHeight, 100, 3);     //100 because Player X always stays 2 so 100 is the 6th slot (which is out  
			tubeVec.emplace_back(temp);             //of map) if the distance between each tube is 20
		}
	}



	//Moving map back by 1 every frame
	playerX--;         //moving back the player

	for (int j = 0; j < tubeVec.size(); j++) {         //moving back the tubes and tube extensions by one every frame
		tubeVec[j].tubeX1--;
		tubeVec[j].tubeX1Extension--;

		tubeVec[j].tubeX2--;
		tubeVec[j].tubeX2Extension--;
	}
	
	
	//Refresh timer
	if (score <= 15)
		Sleep(50);
	else if (score <= 25)
		Sleep(40);
	else
		Sleep(30);
}