#include "Span.hpp"

unsigned int getSpan(int a, int b)
{
	if (a >= b)
		return std::abs(a - b);
	return std::abs(b - a);
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
		Span span(12);
		span.addNumber(std::numeric_limits<int>::min());
		span.addNumber(std::numeric_limits<int>::max());
		span.insert(10, vec.begin(), vec.end()); // to fill span with vec, 10 is the amount of elements

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