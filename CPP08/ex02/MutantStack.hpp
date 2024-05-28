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
		MutantStack(void);
		MutantStack(const std::stack<T>& other);
		~MutantStack(void);
		MutantStack& operator = (const MutantStack& other);

		class iterator {
		private:
			typename std::stack<T>::container_type::iterator it;
		public:
			iterator(typename std::stack<T>::container_type::iterator itr) : it(itr) {}
			~iterator(void) {};
			iterator(const iterator& other) { *this = other; };
			iterator& operator=(const iterator& other) { (void)other; return (*this);};

			T& operator*() { return *it; }
			iterator& operator++() { ++it; return *this; }
			iterator& operator--() { --it; return *this; }
			bool operator!=(const iterator& other) const { return it != other.it; }
		};

		iterator begin() { return iterator(std::stack<T>::c.begin()); }
		iterator end() { return iterator(std::stack<T>::c.end()); }
};

#include "MutantStack.tpp"