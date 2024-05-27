#include "RPN.hpp"

RPN::RPN(string& str) : arg(str)
{

}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN::~RPN(void)
{

}

RPN& RPN::operator = (const RPN& other)
{
	if (this == &other)
		return (*this);

	this->stack = other.stack;
	this->arg = other.arg;

	return (*this);
}

void RPN::stackOps(void)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: Not enough numbers for operations" << endl;
				exit(1);
			}
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (arg[i] == '+')
				stack.push(a + b);
			else if (arg[i] == '-')
				stack.push(a - b);
			else if (arg[i] == '*')
				stack.push(a * b);
			else
			{
				if (a == 0 || b == 0)
				{
					std::cerr << "Error: Division by 0" << endl;
					exit(1);
				}
				stack.push(a / b);
			}
		}
		else
		{
			stack.push(arg[i] - 48);
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << endl;
}