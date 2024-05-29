#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error: the program requires whole numbers as arguments" << endl;
		return (1);
	}

	PmergeMe pm;
	std::cout << std::fixed;
	for(size_t i = 1; argv[i]; i++)
	{
		for(size_t j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				std::cout << "Error: Not a whole or positive number" << endl;
				return (1);
			}
		}
		string str(argv[i]);
		int nb;
		std::istringstream(str) >> nb;
		pm.addDeque(nb);
		pm.addVector(nb);
	}

	clock_t timer = clock();
	pm.printDeque();
	pm.insertionSort();
	timer = clock() - timer;
	std::cout << "Function took " << timer << " clicks and " << (((float)timer)/CLOCKS_PER_SEC) << " seconds." << endl;

	return (0);
}