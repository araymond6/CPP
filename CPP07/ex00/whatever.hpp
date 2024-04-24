#include <iostream>
#include <exception>
#include <cstdlib>
#include <time.h>

template <typename T>
void swap(T &x, T &y)
{
	T z = x;

	x = y;
	y = z;
}

template <typename T>
T min(T x, T y)
{
    if (x < y)
        return (x);
    return (y);
}

template <typename T>
T max(T x, T y)
{
    if (x > y)
        return (x);
    return (y);
}