#include "PMergeMe.hpp"

PMergeMe::PMergeMe(string& str) : arg(str)
{

}

PMergeMe::PMergeMe(const PMergeMe& other)
{
	*this = other;
}

PMergeMe::~PMergeMe(void)
{

}

PMergeMe& PMergeMe::operator = (const PMergeMe& other)
{
	if (this == &other)
		return (*this);

	return (*this);
}