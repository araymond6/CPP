template <typename T>
Array<T>::Array(void) : _array(NULL), _arr_size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_arr_size = n;
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _array(NULL)
{
	if (other._array)
	{
		*this = other;
	}
}

template <typename T>
Array<T>::~Array(void)
{
	if (_array)
		delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return(*this);

	if (other._array)
	{
		if (this->_array)
			delete[] this->_array;
		this->_array = new T[other._arr_size];
		this->_arr_size = other._arr_size;
		for (unsigned int i = 0; i < other._arr_size; i++)
		{
			this->_array[i] = other._array[i];
		}
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index < 0 || index >= _arr_size)
		throw std::out_of_range("Index out of range");

	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	unsigned int i = 0;
	for (;i != _arr_size; i++);

	return (i);
}