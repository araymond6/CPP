#include "Conversion.hpp"

/*
	there is no order to conversions they are done in the type
	detected first and only then, they are converted into the
	other types;

	need to figure out how to properly convert all data, learn how to use nan, nanf, inf, inff
	do try catches to see if a conversion worked

	functions used: atof, atoi, everything string, static_cast<>
*/

int main(int ac, char** av)
{
	if (ac != 2)
		return (1);

	std::string arg(av[1]);
	Conversion convert(arg);

	int type = convert.findType();
	if (type == IMPOSSIBLE)
	{
		std::cout << "char: impossible" << endl;
		std::cout << "int: impossible" << endl;
		std::cout << "float: impossible" << endl;
		std::cout << "double: impossible" << endl;
	}
	else
		convert.convert(type);

	return (0);
}