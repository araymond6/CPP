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

Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << endl;
	this->_fixed = raw << _bits;
}

Fixed::Fixed(float const raw)
{
	std::cout << "Float constructor called" << endl;
	this->_fixed = roundf((float)raw * (float)(1 << _bits));
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

void Fixed::operator = (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << endl;
	if (this != &fixed)
	{
		this->_fixed = fixed.getRawBits();
	}
}

float Fixed::toFloat(void) const
{
	return ((float)_fixed / (float)(1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_fixed >> _bits);
}

int Fixed::getRawBits(void) const
{
    return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}