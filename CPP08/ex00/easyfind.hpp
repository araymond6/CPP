#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
int easyfind(T& container, int nb)
{
	typename T::iterator find = std::find(container.begin(), container.end(), nb);

	if (find != container.end())
		return (0);
	return (1);
}