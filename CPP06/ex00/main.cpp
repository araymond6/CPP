#include "Conversion.hpp"

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