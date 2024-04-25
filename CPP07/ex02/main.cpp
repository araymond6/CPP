#include "Array.hpp"

int main()
{
	Array<int> ar(50);
	Array<int> ar2;

	std::cout << ar.size() << std::endl;
	std::cout << ar2.size() << std::endl;

	try
	{
		std::cout << "Index 49: " << ar[49] << std::endl;
		std::cout << "Index 50: " << ar[50] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}