#include "iter.hpp"

int main()
{
	int size = 3;
	float a[] = {15, 25, 35};

	std::cout << "Before increment: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << std::endl;
	}
	::iter(a, size, &increment);
	std::cout << "After increment: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << std::endl;
	}
	::iter(a, size, &decrement);
	std::cout << "After decrement: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << std::endl;
	}
    return (0);
}