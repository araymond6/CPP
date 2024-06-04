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

	std::deque<int>& deq = pm.getDeque();
	std::vector<int>& vec = pm.getVector();
	std::cout << "Before sort: ";
	pm.printDeque();

	clock_t timer1 = clock();
	pm.mergesort(deq, 0, deq.size() - 1);
	timer1 = clock() - timer1;

	clock_t timer2 = clock();
	pm.mergesort(vec, 0, vec.size() - 1);
	timer2 = clock() - timer2;

	std::cout << "After sort: ";
	pm.printDeque();

	std::cout << "Deque sort took " << timer1 << " clicks and " << (((float)timer1)/CLOCKS_PER_SEC) << " seconds." << endl;
	std::cout << "Vector sort took " << timer2 << " clicks and " << (((float)timer2)/CLOCKS_PER_SEC) << " seconds." << endl;




	return (0);
}