#pragma once

#include <string>


class AsciiConverter
{
public:
	AsciiConverter();

	std::string convertToAscii(std::string text);
	std::string deconvertFromAscii(std::string asciiText);
};