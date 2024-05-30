#include "Span.hpp"

int main()
{
	std::vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(rand() % 4000 - 2000); // just to get numbers
	}

	try
	{
		Span span(12);
		span.addNumber(-950);
		span.addNumber(1585);
		span.insert(10, vec.begin(), vec.end()); // to fill span with vec, 10 is the amount of elements in vec

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
