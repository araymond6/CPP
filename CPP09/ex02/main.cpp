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

	// std::deque<int>& deq = pm.getDeque();
	std::vector<int>& vec = pm.getVector();

	clock_t timer = clock();
	pm.mergesort(vec, 0, vec.size() - 1);
	timer = clock() - timer;
	std::cout << "Function took " << timer << " clicks and " << (((float)timer)/CLOCKS_PER_SEC) << " seconds." << endl;
	pm.printVector();

	return (0);
}