template <typename T>
MutantStack<T>::MutantStack(void)
{
	
}

template <typename T>
MutantStack<T>::MutantStack(const std::stack<T>& other)
{
	*this = other;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{

}

template <typename T>
MutantStack<T>& MutantStack<T>::operator = (const MutantStack<T>& other)
{
	if (this == &other)
		return (*this);
	
	this->stack = other.stack;

	return (*this);
}