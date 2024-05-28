#pragma once
#include <iostream>
#include <stack>

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