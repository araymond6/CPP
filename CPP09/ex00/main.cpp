#include "BitcoinExchange.hpp"

void fileErrorCheck(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open file" << endl;
		exit(1);
	}
	if (file.peek() == std::ifstream::traits_type::eof()) //Checks if file is empty
	{
		file.close();
		std::cerr << "Error: Empty file." << std::endl;
		exit(1);
	}
}

void removeSpaces(string& line)
{
	for(size_t find = line.find(' '); find != string::npos; find = line.find(' '))
	{
		line.erase(find, 1);
	}
}

bool verifyDate(string& date)
{
	// normal format: YYYY-MM-DD
	int year = atoi((date.substr(0, 4)).c_str());
	if (year > 2024 || year < 2009)

	return (false);
}

bool verifyNum(double num)
{
	(void)num;
	return (false);
}

void checkFile(std::ifstream& file, std::map<string, double>& db)
{
	string line;
	string delimiter = "|";
	(void)db;

	while (std::getline(file, line) && file.is_open())
	{
		removeSpaces(line);
		std::cout << line << endl;
		size_t find = line.find('|');
		if (find == string::npos)
		{
			std::cerr << "Error: Bad input" << endl;
			continue ;
		}
		string token1 = line.substr(0, find);
		verifyDate(token1);
		line.erase(0, find + 1);
		string token2 = line;

	}
}

void inputDb(std::ifstream& file, std::map<string, double>& db)
{
	string line;
	char delimiter = ',';
	bool first = true;

	while (std::getline(file, line))
	{
		if (first == true)
		{
			first = false;
			continue ;
		}
		size_t find = line.find(delimiter);

		string token1 = line.substr(0, find);
		line.erase(0, find + 1);
		string token2 = line;
		db.insert(std::make_pair<string, double>(token1, atof(token2.c_str())));
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: the program requires an argument: <file>" << endl;
		return (1);
	}

	// use map.lower_bound for le précédent plus proche

	std::ifstream file(argv[1]);
	std::ifstream database("data.csv");
	fileErrorCheck(file);
	fileErrorCheck(database);

	std::map<string, double> db, input;
	inputDb(database, db);
	checkFile(file, db);
	

	return (0);
}