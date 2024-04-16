#include "Conversion.hpp"

Conversion::Conversion(std::string arg) : _arg(arg)
{

}

Conversion::Conversion(const Conversion& other)
{
	*this = other;
}

Conversion::~Conversion(void)
{

}

Conversion& Conversion::operator = (const Conversion& other)
{
	if (this == &other)
		return (*this);

	

	return (*this);
}

int Conversion::findType(void) // finds the base type of the original string
{
	if (_arg.length() == 1 && _arg.find_first_of("0123456789") == std::string::npos) // char check
		return (CHAR);

	if (_arg.find_first_not_of("-0123456789") == std::string::npos) // int check
	{
		//first if checks if there is a +- in the wrong place
		if (_arg.find_first_of("-") != std::string::npos && _arg.find_first_of("-") == 0 && _arg.find_last_of("-") != 0)
			return (IMPOSSIBLE);
		return (INT);
	}

	if (_arg.find_first_not_of("-0123456789f.") == std::string::npos) // float and double check
	{
		if (_arg.find_first_of("-") != std::string::npos && _arg.find_first_of("-") == 0 && _arg.find_last_of("-") != 0)
			return (IMPOSSIBLE);

		size_t yes = _arg.find_first_of('.');
		if (yes != std::string::npos && _arg.find_first_of('.') != _arg.find_last_of('.') && _arg.front() == '.' && _arg.back() == '.')
			return (IMPOSSIBLE);

		if (_arg.find_last_of('f') != std::string::npos && _arg.find_first_of("f") != _arg.length() - 1)
			return (IMPOSSIBLE);

		if (_arg.find('f') != std::string::npos)
		{
			size_t pos = _arg.find("f");
			//_arg.erase(pos, 1);
			return (FLOAT);
		}

		return (DOUBLE);
	}

	if (_arg == "nanf" || _arg == "+inff" || _arg == "-inff")
		return (FLOAT);

	if (_arg == "nan" || _arg == "+inf" || _arg == "-inf")
		return (DOUBLE);

	return (IMPOSSIBLE);
}

void Conversion::convert(int type)
{
	char c;
	int i;
	float f;
	double d;

	if (type == CHAR)
	{
		c = _arg[0];
		toChar(c);
	}
	else if (type == INT)
	{
		std::istringstream(_arg) >> i;
		toInt(i);
	}
	else if (type == FLOAT)
	{
		if (_arg == "nanf")
			f = nanf("");
		else if (_arg == "+inff")
			f = HUGE_VALF;
		else if (_arg == "-inff")
			f = -HUGE_VALF;
		else
			std::istringstream(_arg) >> f;
		std::cout << f << endl;
		toFloat(f);
	}
	else
	{
		if (_arg == "nan")
			d = nan("");
		else if (_arg == "+inf")
			d = HUGE_VAL;
		else if (_arg == "-inf")
			d = -HUGE_VAL;
		else
			std::istringstream(_arg) >> d;
		toDouble(d);
	}
}

void Conversion::toChar(char c)
{

	if (c >= 32 && c < 127)
		cout << "char: " << c << endl;
	else
		cout << "char: Non displayable" << endl;

	cout << "int: " << static_cast<int>(c) << endl;
	cout << "float: " << std::fixed << static_cast<float>(c) << "f" << endl;
	cout << "double: " << static_cast<double>(c) << endl;
}

void Conversion::toInt(int i)
{
	cout << "char: " << static_cast<char>(i) << endl;
	cout << "int: " << i << endl;
	cout << "float: " << static_cast<float>(i) << "f" << endl;
	cout << "double: " << static_cast<double>(i) << endl;
}

void Conversion::toFloat(float f)
{
	char c = static_cast<char>(f);

	if (c >= 32 && c < 127)
		cout << "char: " << static_cast<char>(f) << endl;
	else
		cout << "char: impossible" << endl;
	
	//check for int limit
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		cout << "int: impossible" << endl;
	else
		cout << "int: " << static_cast<int>(f) << endl;

	cout << std::fixed << "float: " << f << "f" << endl;
	cout << "double: " << static_cast<double>(f) << endl;
}

void Conversion::toDouble(double d)
{
	cout << "char: " << static_cast<char>(d) << endl;
	cout << "int: " << static_cast<int>(d) << endl;
	cout << "float: " << static_cast<float>(d) << "f" << endl;
	cout << "double: " << d << endl;
}