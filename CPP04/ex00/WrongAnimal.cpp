#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal Default constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy constructor called" << endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Default destructor called" << endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "*sound a WrongAnimal makes*" << endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}