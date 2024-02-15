#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat Default constructor called" << endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat Default destructor called" << endl;
}

Cat& Cat::operator = (const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "*mewmew*" << endl;
}