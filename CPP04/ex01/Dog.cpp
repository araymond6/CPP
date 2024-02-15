#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog Default constructor called" << endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Dog Default destructor called" << endl;
	delete this->_brain;
}

Dog& Dog::operator = (const Dog& other)
{
	std::cout << "Dog Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_type = other._type;
		if (this->_brain)
		{
			delete this->_brain;
			_brain = NULL;
		}
		if (other._brain)
		{
			this->_brain = new Brain();
			for (int i = 0; i < IDEACOUNT; i++)
			{
				this->_brain[i] = other._brain[i];
			}
		}
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "*woofwoof*" << endl;
}