#include "inputHandler.h"
#include "asciiConverter.h"

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>




void showOldNotes();
void createNewNote();
void fileNameHandling();






int main()
{
	fileNameHandling();


	int eXIT;
	std::cin >> eXIT;
}


/// <summary>
/// Lists up all existing notes and lets the user choose to open one and then decrypts it
/// </summary>
void showOldNotes()
{
	//Get all the files with .txt from the current folder and put them into a vector
	auto currentPath = std::filesystem::current_path().string();
	std::vector<std::string> files;
	for(const auto& entry : std::filesystem::directory_iterator(currentPath))
	{
		std::string filePath = entry.path().string();

		//If the file ends with .txt
		if(filePath[ filePath.length() - 1 ] == 't' && filePath[ filePath.length() - 2 ] == 'x' && filePath[ filePath.length() - 3 ] == 't' &&
			filePath[ filePath.length() - 4 ] == '.')
		{
			files.emplace_back(entry.path().string());
		}
	}


	//Remove all the path, let only the file name in
	for(int file = 0; file < files.size(); file++)
	{
		std::string trimmedPath{};
		for(int character = files[ file ].length(); character > 0; character--)
		{
			if(files[ file ][ character ] != '\\')   //Checks for one backslash ('\\' == '\')
			{
				trimmedPath += files[ file ][ character ];
			}
			else
			{
				break;
			}
		}

		std::reverse(trimmedPath.begin(), trimmedPath.end());

		files[ file ] = trimmedPath;
	}


	//Print all files
	for(int i = 0; i < files.size(); i++)
	{
		std::cout << i << ". " << files[ i ] << '\n';
	}

	std::cout << "Type the number for the file you want to open\n";

	int choosedFile{ 0 };
	std::cin >> choosedFile;


	std::string fileContent{};
	std::fstream file;
	file.open(files[ choosedFile ] + ".txt", std::ios::in);
	if(file.is_open())
	{
		std::getline(file, fileContent);
	}

	AsciiConverter asciiConverter = AsciiConverter();
	std::string deconvertedString = asciiConverter.deconvertFromAscii(fileContent);

	system("CLS");
	std::cout << deconvertedString << '\n';
	
	while(true)
	{
		std::string s;
		std::cin >> s;
		if(s == ":q")
		{
			break;
		}
	}

	fileNameHandling();
}


/// <summary>
/// Creates a new note, lets the user choose the name and content, then encrypts it and stores it locally
/// </summary>
void createNewNote()
{
	std::string name;
	while(true)
	{
		//Asks user for name
		std::cout << "How do you want to name your note?: ";
		name = "";
		std::cin >> name;
		system("CLS");

		//Checks if file already exists
		std::filesystem::path f{ name + ".txt" };
		if(std::filesystem::exists(f))
		{
			system("CLS");
			std::cout << "A file with the name " + name + " already exists, please choose another one!\n";
		}
		else
		{
			break;
		}
	}


	//Asks user for content
	system("CLS");
	std::cout << "Your text here:\n";


	InputHandler inputHandler = InputHandler();
	AsciiConverter asciiConverter = AsciiConverter();

	//reads in text
	while(inputHandler.readInText());


	//Encrypts text
	std::string convertedText = asciiConverter.convertToAscii(inputHandler.text);

	//Writes encrypted content to file
	std::fstream file;
	file.open(name + ".txt", std::ios::out);
	if(file.is_open())
	{
		file << convertedText;
		file.close();
	}

	fileNameHandling();
}


/// <summary>
/// Checks for user input to what he wants to do
/// </summary>
void fileNameHandling()
{
	while(true)
	{
		system("CLS");
		std::cout << "If you want to create a new note, enter: 1\n"
			"If you want to read a old note, enter: 2\n"
			"If you want to quit enter: 0\n";

		int x{ 0 };
		try
		{
			std::cin >> x;
			system("CLS");
			if(x == 1)
			{
				createNewNote();
				break;
			}
			else if(x == 2)
			{
				showOldNotes();
				break;
			}
			else if(x == 0)
			{
				exit(1);
			}
			throw std::range_error("not in range");
		}
		catch(...)
		{
			std::cout << "[ERROR] Please type in a valid unsigned integral type between 0 and 2!\n\n";
		}
	}
}