#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called" << endl;
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Default destructor called" << endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other)
{
	std::cout << "WrongCat Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "*wrongmewmew*" << endl;
}