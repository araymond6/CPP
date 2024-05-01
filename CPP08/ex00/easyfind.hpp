#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
ssize_t easyfind(T& container, int nb) //uses ssize_t to be able to return -1
{
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i] == nb)
			return (i);
	}

	return (-1);
}