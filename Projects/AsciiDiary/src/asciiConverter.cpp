#include "asciiConverter.h"

#include <sstream>

AsciiConverter::AsciiConverter() {}

std::string AsciiConverter::convertToAscii(std::string text)
{
	std::string convertedText{};

	for(char letter : text)
	{
		auto x = int(letter);

		//int to string conversion by passing int into stringstream
		std::stringstream ss;
		ss << x;
		std::string convertedInt;
		ss >> convertedInt;

		convertedText.append(convertedInt);
		convertedText.append(":");
	}

	return convertedText;
}

std::string AsciiConverter::deconvertFromAscii(std::string asciiText)
{
	std::string resPlaneText{};

	std::string temp{};
	for(auto c : asciiText)
	{
		if(c != ':')
		{
			temp += c;
		}
		else
		{
			resPlaneText += char(std::stoi(temp));
			temp = "";
		}
	}

	return resPlaneText;
}
