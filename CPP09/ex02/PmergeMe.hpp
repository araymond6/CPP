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
		size_t dequeSize(void) { return (deq.size()); };
		size_t vectorSize(void) { return (vec.size()); };
		void printDeque(void);
		void printVector(void);

		//algorithm methods
		void insertionSort(void);
		void merge(int left, int middle, int right);
		void mergesort();

};