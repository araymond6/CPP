#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:

		Array(void);
		Array(unsigned int uint);
		Array(const Array& other);
		~Array(void);

		Array& operator=(const Array& other);
		T& operator[](size_t index);

		unsigned int size(void) const;

	private:

		T* _array;
		unsigned int _arr_size;
};

#include "Array.tpp"