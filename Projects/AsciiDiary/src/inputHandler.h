#pragma once

#include <string>


class InputHandler
{
public:
	std::string text{};

public:
	InputHandler();

	bool readInText();
};