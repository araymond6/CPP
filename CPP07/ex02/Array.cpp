#include "Array.hpp"

template<class T>
Array<T>::Array(void) : _array(NULL)
{
}

template<class T>
Array<T>::Array(const Array<T>& other) : _array(NULL)
{
	if (this == &other)
		return;

	if (other->_array)
	{
		
	}
}

template<class T>
Array<T>::Array(unsigned int n)
{
	try
	{
		_array = new T[n];
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template<class T>
Array<T>::~Array(void)
{
	if (_array)
		delete[] _array;
}

template<class T>
unsigned int Array<T>::size(void) const
{
	unsigned int i = 0;
	for (;_array[i] != NULL; i++);

	return (i);
}