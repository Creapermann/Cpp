#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <conio.h>
#include <Windows.h>


struct Tail
{
public:
	int posX;
	int posY;
};

struct Fruit {
	int posX;
	int posY;
};


bool gameOver = false;

const int fieldWidth = 40;
const int fieldHeight = 15;

int snakeHeadX;
int snakeHeadY;

std::vector<Tail> snakeTailVec;
std::vector<Fruit> fruitVec;

int prevSnakeHeadY;
int prevSnakeHeadX;


int score = 0;

std::default_random_engine rndmGen(time(NULL));
std::uniform_int_distribution<int> fruitXNum(1, fieldWidth - 1);
std::uniform_int_distribution<int> fruitYNum(0, fieldHeight);


enum eDirection {
	STOP = 0, UP, DOWN, LEFT, RIGHT
};

eDirection dir;
eDirection compDir;



void createNewFruit() {

	Fruit tempFruit;
	tempFruit.posX = fruitXNum(rndmGen);
	tempFruit.posY = fruitYNum(rndmGen);
	fruitVec.emplace_back(tempFruit);
}

void init() {

	snakeHeadX = fieldWidth / 2;
	snakeHeadY = fieldHeight / 2;

	createNewFruit();
}


void reset() {
	score = 0;

	snakeTailVec.clear();
	fruitVec.clear();

	dir = STOP;
}


void draw() {
	system("CLS");

	//Draw the Field
	for (int i = 0; i <= fieldWidth; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;


	for (int i = 0; i <= fieldHeight; i++) {
		for (int k = 0; k <= fieldWidth; k++) {

			if (k == 0 || k == fieldWidth)					 //End of field
				std::cout << "#";			

			else if (i == snakeHeadY && k == snakeHeadX)
				std::cout << "O";							 //Snake head check


			else {
				bool print = false;
				for (int j = 0; j < fruitVec.size(); j++) {
					if ( k == fruitVec[j].posX && i == fruitVec[j].posY) {
						std::cout << "M";                    //Fruit check
						print = true;
					}
				}


				
				for (int j = 0; j < snakeTailVec.size(); j++) {
					if (snakeTailVec[j].posX == k && snakeTailVec[j].posY == i) {
						std::cout << "o";
						print = true;
					}
				}

				if(print == false)
					std::cout << " ";							 //Default Case
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i <= fieldWidth; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;

	//Draw the Score
	std::cout << "SCORE: " << score << std::endl;
}



void input() {


	if (_kbhit()) {
		char c = _getch();
		switch (c) {
		case 'w':
			if(compDir != UP || snakeTailVec.size() == 0)
				dir = UP;
			break;
		case 'a':
			if (compDir != LEFT || snakeTailVec.size() == 0)
				dir = LEFT;
			break;
		case 's':
			if (compDir != DOWN || snakeTailVec.size() == 0)
				dir = DOWN;
			break;
		case 'd':
			if (compDir != RIGHT || snakeTailVec.size() == 0)
				dir = RIGHT;
			break;
		}
	}
}



void resetFruit(Fruit &fruit) {
	int x = fruitXNum(rndmGen);
	int y = fruitYNum(rndmGen);
	
	bool isntOnFruit = true;
	for (int i = 0; i < fruitVec.size(); i++) {
		if (x == fruitVec[i].posX && y == fruitVec[i].posY) {
			isntOnFruit = false;
		}
	}


	if (!(x == snakeHeadX && y == snakeHeadY) || isntOnFruit == true) {
		fruit.posX = x;
		fruit.posY = y;
	}
	else {
		resetFruit(fruit);
	}
}


void logic() {

	//comp dir setup
	if (true /*No use, just for closing purpose*/) {
		if (dir == UP)
			compDir = DOWN;
		else if (dir == DOWN)
			compDir = UP;
		else if (dir == LEFT)
			compDir = RIGHT;
		else if (dir == RIGHT)
			compDir = LEFT;
	}

	//for the snake tail movement
	prevSnakeHeadX = snakeHeadX;
	prevSnakeHeadY = snakeHeadY;

	//Movement
	switch (dir) {
	case UP:
		if((snakeHeadY - 1) >= 0)
			snakeHeadY--;
		else
			gameOver = true;
		break;
	case LEFT:
		if ((snakeHeadX - 1) >= 1)
			snakeHeadX--;
		else
			gameOver = true;
		break;
	case DOWN:
		if ((snakeHeadY + 1) <= fieldHeight)
			snakeHeadY++;
		else
			gameOver = true;
		break;
	case RIGHT:
		if ((snakeHeadX + 1) <= fieldWidth - 1)
			snakeHeadX++;
		else
			gameOver = true;
		break;
	}
	

	//Fruit Collider
	for (int i = 0; i < fruitVec.size(); i++) {
		if (snakeHeadX == fruitVec[i].posX && snakeHeadY == fruitVec[i].posY) {
			resetFruit(fruitVec[i]);       //gives the fruit a new location

			score++;					   //adds up the score

			//Adds the tail
			Tail temp;
			temp.posX = 0;
			temp.posY = 0;
			snakeTailVec.push_back(temp);
		}
	}

	//Snake Tail Movement
	if (snakeTailVec.size() > 0) {
		int prevX = snakeTailVec[0].posX;
		int prevY = snakeTailVec[0].posY;


		snakeTailVec[0].posX = prevSnakeHeadX;
		snakeTailVec[0].posY = prevSnakeHeadY;

		int prevX2 = 0;
		int prevY2 = 0;

		for (int i = 1; i < snakeTailVec.size(); i++) {
			prevX2 = snakeTailVec[i].posX;
			prevY2 = snakeTailVec[i].posY;

			snakeTailVec[i].posX = prevX;
			snakeTailVec[i].posY = prevY;

			prevX = prevX2;
			prevY = prevY2;
		}
	}


	//Snake Tail Collision
	for (int i = 0; i < snakeTailVec.size(); i++) {
		if (snakeTailVec[i].posX == snakeHeadX && snakeTailVec[i].posY == snakeHeadY) {
			gameOver = true;
		}
	}


	//increase Fruit amount
	if (score == 10 && fruitVec.size() < 2)
		createNewFruit();
	if (score == 20 && fruitVec.size() < 3)
		createNewFruit();
	if (score == 30 && fruitVec.size() < 4)
		createNewFruit();
	if (score == 40 && fruitVec.size() < 5)
		createNewFruit();
	if (score == 50 && fruitVec.size() < 6)
		createNewFruit();
	if (score == 60 && fruitVec.size() < 7)
		createNewFruit();

	//Managing movement speed with Sleep()
	if (true /*No use, just for closing purpose*/) {
		if (dir == UP) {
			Sleep(150);
		}
		else if (dir == LEFT) {
			Sleep(75);
		}
		else if (dir == DOWN) {
			Sleep(150);
		}
		else if (dir == RIGHT) {
			Sleep(75);
		}
		else {
			Sleep(200);
		}
	}
}






int main() {

	init();
	
	while (gameOver != true) {
		draw();
		input();
		logic();
	}

	std::string a;
	std::cin >> a;
	
	if (a == "rs" || a == "RS") {
		reset();
		gameOver = false;
		main();
	}

	std::cin.get();
	return 0;
}