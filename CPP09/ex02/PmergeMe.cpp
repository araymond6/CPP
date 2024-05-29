#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe& PmergeMe::operator = (const PmergeMe& other)
{
	if (this == &other)
		return (*this);

	return (*this);
}

void PmergeMe::printDeque(void)
{
	for(std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		if (it + 1 != deq.end())
			std::cout << *it << " ";
		else
			std::cout << *it << endl;
	}
}

void PmergeMe::printVector(void)
{
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it + 1 != vec.end())
			std::cout << *it << " ";
		else
			std::cout << *it << endl;
	}
}

void PmergeMe::insertionSort(void) // does this work?
{
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::rotate(std::upper_bound(deq.begin(), it, *it), it, it+1);
	}
	printDeque();
}