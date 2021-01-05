#include <iostream>
#include <Windows.h>




class Pong
{
public:
	Pong();
	void init();
	void draw();
	void input();
	void logic();

	//Utility
	void resetBall();
	
private:
	//Field
	int fieldWidth;
	int fieldHeight;
	//Players
	int playerLeftX;
	int playerLeftY;
	
	int playerRightX;
	int playerRightY;

	int playerHeight;
	//Player Movement
	enum class player {
		STOP = 0, UP, DOWN
	};

	player PlayerLeft;
	player PlayerRight;
	//Ball
	int ballPosX;
	int ballPosY;

	enum class ball {
		STOP = 0, LEFT, RIGHT
	};
	ball ballDir;

	int ballAngle;
	//Score
	int score;

	int scorePosX;
	int scorePosY;
	//Game
	bool gameOver;
};