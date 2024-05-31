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

void PmergeMe::printDeque(void) const
{
	for(std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
	{
		if (it + 1 != deq.end())
			std::cout << *it << " ";
		else
			std::cout << *it << endl;
	}
}

void PmergeMe::printVector(void) const
{
	for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it + 1 != vec.end())
			std::cout << *it << " ";
		else
			std::cout << *it << endl;
	}
}

std::deque<int>& PmergeMe::getDeque(void)
{
	return (deq);
}

std::vector<int>& PmergeMe::getVector(void)
{
	return (vec);
}