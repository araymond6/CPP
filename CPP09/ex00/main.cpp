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

bool verifyDate(string& date) // do all the verification for the date: year, month and day
{
	// normal format: YYYY-MM-DD
	int year, month, day;

	std::istringstream(date.substr(0, 4)) >> year; //= atoi((date.substr(0, 4)).c_str());
	std::istringstream(date.substr(5, 7)) >> month;
	std::istringstream(date.substr(8, 10)) >> day;

	if (month > 12 || month < 1 || day > 31 || day < 1)
		return (false);
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	
	if(year % 4 == 0) // for leap years
	{
		if (!(year % 100 == 0 && year % 400 == 0)) // not a leap year, only exceptions
		{
			if (month == 2 && day > 29)
			return false;
		}	
	}
	else if (month == 2 && day > 28)
		return (false);

	return (true);
}

bool verifyNum(string& line)
{
	double num;

	std::istringstream(line) >> num;
	if (num < 0 || num > 1000)
		return (false);
	return (true);
}

bool verifyFormat(string& line)
{
	size_t find = line.find('-');
	if (find != 4)
		return (false);
	else if ((find = line.find('-', find + 1)) != 7)
		return (false);

	find = line.find('|');
	if (find == string::npos || find == line.length())
		return (false);
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(line.at(i)))
			return (false);
	}
	
	string token = line.substr(find + 1); // for the double
	if (token.find_first_not_of("0123456789.") != string::npos)
		return (false);
	find = token.find_first_of('.');
	if ((find != std::string::npos && token.find_first_of('.') != token.find_last_of('.')) || token.front() == '.' || token.back() == '.')
		return (false); // checks for if '.' is wrongly placed, if present

	return (true);
}

double btcExchange(std::map<string, double>& db, string date, string num)
{
	double f;
	std::istringstream(num) >> f;
	std::map<string, double>::iterator it = db.find(date);
	if (it != db.end())
		return (it->second * f);
	else
	{
		it = db.lower_bound(date);
		if (it != db.begin())
			it--;
		return (it->second * f);
	}

	return (0);
}

void checkFile(std::ifstream& file, std::map<string, double>& db)
{
	string line;
	string delimiter = "|";

	while (std::getline(file, line) && file.is_open())
	{
		removeSpaces(line);
		if (verifyFormat(line) == false)
		{
			std::cerr << "Error: Bad format, format has to be 'YYYY-MM-DD | NUM'" << endl;
			continue ;
		}
		size_t find = line.find('|');
		string token1 = line.substr(0, find);
		if (verifyDate(token1) == false)
		{
			std::cerr << "Error: Bad date, please use a valid date as input" << endl;
			continue ;
		}
		string token2 = line.substr(find + 1);
		if (verifyNum(token2) == false)
		{
			std::cerr << "Error: Bad number, value has to be between 0 and 1000" << endl;
			continue ;
		}
		std::cout << line << " -> " << btcExchange(db, token1, token2) << endl;
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

	std::ifstream file(argv[1]);
	std::ifstream database("data.csv");
	fileErrorCheck(file);
	fileErrorCheck(database);

	std::map<string, double> db;
	inputDb(database, db);
	checkFile(file, db);
	

	return (0);
}