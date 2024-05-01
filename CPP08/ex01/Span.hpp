#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(void);
		Span(unsigned int i);
		Span(const Span& other);
		~Span(void);

		Span& operator = (const Span& other);

		void addNumber(int num);
		int shortestSpan(void);
		int longestSpan(void);
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
		class BadInsertException : public std::exception
		{
			virtual char const* what() const throw() { return("Bad insert exception."); };
		};

	private:
		size_t _limit;
		std::vector<int> _span;
};

int getSpan(int a, int b);