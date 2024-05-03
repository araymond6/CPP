#pragma once
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	std::stack<T> stack;

	public:
	//constructors, destructor and operator =
	MutantStack(void);
	MutantStack(const std::stack<T>& other);
	~MutantStack(void);
	MutantStack& operator = (const MutantStack& other);

	//member functions (not needed since you can just use std::stack<T>)
	// bool empty() const { return (stack.empty()); }
	// size_t size() const { return (stack.size()); }
	// T& top() { return(stack.top()); }
	// const T& top() const { return (stack.top()); }
	// void push(const T& value) { stack.push(value); }
	// void pop() { stack.pop(); }

	
	class iterator {
	private:
		typename std::stack<T>::container_type::iterator it;
	public:
		iterator(typename std::stack<T>::container_type::iterator itr) : it(itr) {}

		T& operator*() { return *it; }
		iterator& operator++() { ++it; return *this; }
		iterator& operator--() { --it; return *this; }
		bool operator!=(const iterator& other) const { return it != other.it; }
	};

	iterator begin() { return iterator(std::stack<T>::c.begin()); }
	iterator end() { return iterator(std::stack<T>::c.end()); }
};

#include "MutantStack.tpp"