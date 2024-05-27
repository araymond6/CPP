#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <algorithm>

using std::endl;
using std::string;

class RPN
{
	private:
		std::stack<int> stack;
		string arg;
		RPN(void);

	public:
		RPN(string& str);
		~RPN(void);
		RPN(const RPN& other);
		RPN& operator = (const RPN& other);

		void stackOps(void);
};