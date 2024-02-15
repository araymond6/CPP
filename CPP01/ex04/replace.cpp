#include "replace.h"

void errorCheck(std::ifstream &file, char **argv)
{
	if (!file.is_open()) //Checks if file can be opened
	{
		std::cerr << "Error: Unable to open file." << std::endl;
		exit(1);
	}
	if (file.peek() == std::ifstream::traits_type::eof()) //Checks if file is empty
	{
		file.close();
		std::cerr << "Error: Empty file." << std::endl;
		exit(1);
	}
	std::string oldString = argv[2];
	if (oldString.size() == 0) //Checks if string to replace is invalid
	{
		file.close();
		std::cerr << "Error: String to replace is of size 0. ";
		std::cerr << "Please enter a string of at least 1 character." << std::endl;
		exit(1);
	}
}

void readAndCreateFile(std::ifstream &file, char **argv)
{
	std::string line;
	std::string newFile = argv[1];
	std::string oldString = argv[2];
	std::string newString = argv[3];
	std::ofstream replaceFile(newFile.append(".replace"));

	if (!replaceFile.is_open())
	{
		file.close();
		std::cerr << "Error: Unable to write to file." << std::endl;
		exit(1);
	}

	while (std::getline(file, line) && file.is_open())
	{
		size_t find = 0;
		while ((find = line.find(oldString, find)) != std::string::npos)
		{
			line.erase(find, oldString.size());
			line.insert(find, newString);
			find += newString.size();
		}
		
		if (file.peek() != std::ifstream::traits_type::eof())
			replaceFile << line << std::endl;
		else
			replaceFile << line;
	}
	file.close();
	replaceFile.close();
}