#include "replace.h"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream file(argv[1]);
		errorCheck(file, argv);
		readAndCreateFile(file, argv);
	}
	else
	{
		std::cerr << "Error: The program requires 3 additional arguments: <file> <string_to_replace> <replacement>." << std::endl;
		return (1);
	}
	return (0);
}