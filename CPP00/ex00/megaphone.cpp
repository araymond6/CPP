#include <iostream>
#include <cctype>
#include <string.h>

void megaphone(char **argv)
{
	for (int i = 1; argv[i] != NULL; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		megaphone(argv);
	}

	return (0);
}