#include <iostream>
#include <exception>
#include <cstdlib>
#include <time.h>

template <typename T>
void increment(T &inc)
{
	inc++;
}

template <typename T>
void decrement(T &inc)
{
	inc--;
}

template <typename T>
void iter(T *tab, size_t size, void (*f)(T&))
{
	if (!tab)
		return ;
	for (size_t i = 0; i < size; i++)
		f(tab[i]);
}