#include <iostream>
#include <Windows.h>
#include <ctime>
#include <random>

#include "tube.hpp"

class FlappyBird
{
public:
	FlappyBird();
	
	void init();
	void draw();
	void input();
	void logic();

	

private:
	//Field
	int fieldWidth;
	int fieldHeight;
	//Player
	int playerX;
	int playerY;
	//Player Movement
	enum class player {
		STOP = 0, UP, DOWN
	};
	player playerDir = player::DOWN;
	//Tubes
	std::vector<Tube> tubeVec;

	int firstTubeX = 20;
	int prevTubeX;
	//Score
	int score = 0;
	//Utility
	bool gameOver = false;

	
};