#pragma once
#include <iostream>
#include <exception>

using std::endl;
using std::string;

class PmergeMe
{
	private:


	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator = (const PmergeMe& other);
};