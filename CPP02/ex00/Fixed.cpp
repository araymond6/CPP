#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
	std::cout << "Default constructor called" << endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called" << endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << endl;
	*this = fixed;
}

void Fixed::operator = (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << endl;
    if (this != &fixed)
	{
		this->_fixed = fixed.getRawBits();
	}
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << endl;
    return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << endl;
	this->_fixed = raw;
}