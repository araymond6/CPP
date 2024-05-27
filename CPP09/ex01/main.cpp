#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: the program requires an argument: <reverse polish notation mathematical equation>" << endl;
		return (1);
	}

	std::stack<int> stack; 
	string arg(argv[1]);

	for(size_t find = arg.find(' '); find != string::npos; find = arg.find(' '))
		arg.erase(find, 1); // removes spaces
	if (arg.find_first_not_of("0123456789+-/*") != string::npos)
	{
		std::cerr << "Error: Wrong character detected" << endl;
		return (1);
	}
	RPN rpn(arg);
	rpn.stackOps();

	return (0);
}