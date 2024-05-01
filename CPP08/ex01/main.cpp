#include "Span.hpp"

int getSpan(int a, int b)
{
	if (a >= b)
		return (a - b);
	return (b - a);
}

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(25 + i + i*15);
	}


	try
	{
		Span span(11);
		span.addNumber(5);
		span.insert(10, vec.begin(), vec.end());

		std::cout << "Size: " << span.size() << std::endl;
		span.print();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}