#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

class Span
{
	public:
		Span(void);
		Span(unsigned int i);
		Span(const Span& other);
		~Span(void);

		Span& operator = (const Span& other);

		void addNumber(int num);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		void insert(unsigned int n, std::vector<int>::iterator start, std::vector<int>::iterator end);
		size_t size(void) const;
		void print(void);

		class OutOfRangeException : public std::exception
		{
			virtual char const* what() const throw() { return("Out of range exception."); };
		};
		class NoSpanException : public std::exception
		{
			virtual char const* what() const throw() { return("No span exception."); };
		};
		class NoSpaceException : public std::exception
		{
			virtual char const* what() const throw() { return("No space exception."); };
		};

	private:
		size_t _limit;
		std::vector<int> _span;
};

unsigned int getSpan(int a, int b);