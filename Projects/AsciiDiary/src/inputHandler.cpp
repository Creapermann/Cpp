#include "inputHandler.h"

#include <iostream>
#include <iomanip>


InputHandler::InputHandler(){}

bool InputHandler::readInText()
{
	std::string temp;
	std::getline(std::cin >> std::ws, temp);

	if(temp != ":q")
	{
		text += " " + temp;
		return true;
	}
	else
	{
		return false;
	}
}
