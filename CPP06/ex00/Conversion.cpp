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
		
		long long l;
		std::istringstream(_arg) >> l; // for int limit
		if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
			return (IMPOSSIBLE);
		return (INT);
	}

	if (_arg.find_first_not_of("-0123456789f.") == std::string::npos) // float and double check
	{
		if (_arg.find_first_of("-") != std::string::npos && _arg.find_first_of("-") == 0 && _arg.find_last_of("-") != 0)
			return (IMPOSSIBLE);
		size_t yes = _arg.find_first_of('.');
		if ((yes != std::string::npos && _arg.find_first_of('.') != _arg.find_last_of('.')) || _arg.front() == '.' || _arg.back() == '.')
			return (IMPOSSIBLE);
		if (_arg.find_last_of('f') != std::string::npos && _arg.find_first_of("f") != _arg.length() - 1)
			return (IMPOSSIBLE);
		if (_arg.find('f') != std::string::npos)
		{
			size_t pos = _arg.find("f");
			_arg.erase(pos, 1);
			double d;
			std::istringstream(_arg) >> d; // for float limit
			if (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max())
				return (IMPOSSIBLE);
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
	else if ((c < 32 && c >= 0) || c == 127)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: impossible" << endl;

	cout << "int: " << static_cast<int>(c) << endl;
	cout << "float: " << std::fixed << static_cast<float>(c) << "f" << endl;
	cout << "double: " << static_cast<double>(c) << endl;
}

void Conversion::toInt(int i)
{
	if (i >= 32 && i < 127)
		cout << "char: " << static_cast<char>(i) << endl;
	else if ((i < 32 && i >= 0) || i == 127)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: impossible" << endl;

	cout << "int: " << i << endl;
	cout << std::fixed << "float: " << static_cast<float>(i) << "f" << endl;
	cout << "double: " << static_cast<double>(i) << endl;
}

void Conversion::toFloat(float f)
{
	if (f >= 32 && f < 127)
		cout << "char: " << static_cast<char>(f) << endl;
	else if ((f < 32 && f >= 0) || f == 127)
		cout << "char: Non displayable" << endl;
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
	if (d >= 32 && d < 127)
		cout << "char: " << static_cast<char>(d) << endl;
	else if ((d < 32 && d >= 0) || d == 127)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: impossible" << endl;


	//check for int limit
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		cout << "int: impossible" << endl;
	else
		cout << "int: " << static_cast<int>(d) << endl;
	
	//check for float limit
	if (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max())
		cout << "float: impossible" << endl;
	else
		cout << std::fixed << "float: " << static_cast<float>(d) << "f" << endl;

	cout << std::fixed << "double: " << d << endl;
}