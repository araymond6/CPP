#pragma once
#include <iostream>
#include <exception>
#include <cctype>
#include <deque>
#include <vector>
#include <sstream>
#include <ctime>
#include <algorithm>

using std::endl;
using std::string;

class PmergeMe
{
	private:
		std::deque<int> deq;
		std::vector<int> vec;

	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator = (const PmergeMe& other);

		// containers utils
		void addDeque(int num) { deq.push_back(num); };
		void addVector(int num) { vec.push_back(num); };
		size_t dequeSize(void) const { return (deq.size()); };
		size_t vectorSize(void) const { return (vec.size()); };
		void printDeque(void) const;
		void printVector(void) const;
		std::deque<int>& getDeque(void);
		std::vector<int>& getVector(void);

		//algorithm methods
		template <typename T>
		void insertionsort(T& ctn, int left, int right);

		template <typename T>
		void merge(T& ctn, int left, int middle, int right);

		template <typename T>
		void mergesort(T& ctn, int left, int right);

};

template <typename T>
void PmergeMe::insertionsort(T& ctn, int left, int right)
{
	// for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
	// {
	// 	std::rotate(std::upper_bound(deq.begin(), it, *it), it, it+1);
	// }
	// printDeque();

	for (int i = left; i < right; i++)
	{
		int tmp = ctn[i + 1];
		int j = i + 1;
		while (j > left && ctn[j - 1] > tmp)
		{
			ctn[j] = ctn[j - 1];
			j--;
		}
		ctn[j] = tmp;
	}
}

template <typename T>
void PmergeMe::merge(T& ctn, int left, int middle, int right)
{
	//stack overflow implementation
	// int i = left;
	// int j = middle + 1;
	// int k = left;
	// while(i <= middle && j <= right)
	// {
	// 	if (ctn[i] < ctn[j])
	// 	{
	// 		tmp[k] = ctn[i];
	// 		i++;
	// 	}
	// 	else
	// 	{
	// 		tmp[k] = ctn[j];
	// 		j++;
	// 	}
	// }
	// for (; j <= right; j++, k++)
	// 	tmp[k] = ctn[j];
	// for (; i <= middle; i++, k++)
	// 	tmp[k] = ctn[i];
	// for (i = left; i <= right; i++)
	// 	ctn[i] = tmp[i];

	// opengenus implementation
	int n1 = middle - left + 1;
	int n2 = right - middle;
	T tmpa(ctn.begin() + left, ctn.begin() + middle + 1);
	T tmpb(ctn.begin() + middle + 1, ctn.begin() + right + 1);
	int r = 0;
	int l = 0;

	for (int i = left; i < right - left + 1; i++)
	{
		if (r == n2)
		{
			ctn[i] = tmpa[l];
			l++;
		}
		else if (l == n1)
		{
			ctn[i] = tmpb[r];
			r++;
		}
		else if (tmpb[r] > tmpa[l])
		{
			ctn[i] = tmpa[l];
			l++;
		}
		else
		{
			ctn[i] = tmpb[r];
			r++;
		}
	}
}

template <typename T>
void PmergeMe::mergesort(T& ctn, int left, int right)
{
	if (right - left > 1) // num indicates threshold
	{
		int middle = (left + right) / 2;
		mergesort(ctn, left, middle);
		mergesort(ctn, middle + 1, right);
		merge(ctn, left, middle, right);
	}
	else
		insertionsort(ctn, left, right);
}