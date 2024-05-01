#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	int nb;

	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	nb = 8;

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	//if nb is found
	std::cout << "First occurence of " << nb << " is at index: " << easyfind(vec, nb) << std::endl;
	
	//if nb is not found
	nb = 159;
	std::cout << "First occurence of " << nb << " is at index: " << easyfind(vec, nb) << std::endl;

    return (0);
}