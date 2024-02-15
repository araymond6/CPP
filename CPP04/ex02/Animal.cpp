#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal Default constructor called" << endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal Copy constructor called" << endl;
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Animal Default destructor called" << endl;
}

Animal& Animal::operator = (const Animal& other)
{
	std::cout << "Animal Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "*sound an animal makes*" << endl;
}

void Animal::printSound(void)
{
	this->makeSound();
}

std::string Animal::getType(void) const
{
	return (this->_type);
}