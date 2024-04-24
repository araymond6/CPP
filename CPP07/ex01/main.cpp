#include "iter.hpp"

int main()
{
	int size = 3;
	float a[] = {15, 25, 35};

	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << std::endl;
	}
	::iter(a, size, &increment);
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << std::endl;
	}
    return (0);
}