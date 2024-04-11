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

		if (_arg.find('f') != std::string::npos && _arg.find_first_of("f") != _arg.length())
			return (IMPOSSIBLE);

		if (_arg.find('f') != std::string::npos)
			return (FLOAT);
		return (DOUBLE);
	}

	if (_arg == "nanf" || _arg == "+inff" || _arg == "-inff")
		return (FLOAT);

	if (_arg == "nan" || _arg == "+inf" || _arg == "-inf")
		return (DOUBLE);

	return (IMPOSSIBLE);
}

void Conversion::toChar(int type)
{
	if (type != CHAR)
	{
		static_cast<char>()
	}
}

void Conversion::toInt(int type)
{
	
}

void Conversion::toFloat(int type)
{

}