#include <random>

#include "tube.hpp"



Tube::Tube(int fieldHeight, int x, int gapSize) {
	std::default_random_engine rndmGen{ std::random_device{}() };
	std::uniform_int_distribution<int> rndmTubeLength{ 2, 16 };

	//Tube 1
	tubeSize1 = rndmTubeLength(rndmGen);
	tubeX1 = x;
	tubeX1Extension = tubeX1 + 1;
	tubeY1 = 0;

	//Tube 2
	tubeSize2 = (fieldHeight - tubeSize1 - gapSize);    //Calculates the size of the bottom tube
	tubeX2 = x;
	tubeX2Extension = tubeX2 + 1;
	tubeY2 = fieldHeight - 1;
}