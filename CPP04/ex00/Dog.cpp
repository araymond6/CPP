#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Default constructor called" << endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Dog Default destructor called" << endl;
}

Dog& Dog::operator = (const Dog& other)
{
	std::cout << "Dog Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "*woofwoof*" << endl;
}