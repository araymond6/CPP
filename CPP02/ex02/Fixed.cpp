#include "Fixed.hpp"

// Constructors and destructor

Fixed::Fixed(void) : _fixed(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed::Fixed(int const raw)
{
	this->_fixed = raw << _bits;
}

Fixed::Fixed(float const raw)
{
	this->_fixed = roundf((float)raw * (float)(1 << _bits));
}

// Member operator overload functions

void Fixed::operator = (const Fixed& fixed)
{
	if (this != &fixed)
	{
		this->_fixed = fixed.getRawBits(); // TODO: add some kind of destructor, according to pdf
	}
}

bool Fixed::operator > (const Fixed& fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator < (const Fixed& fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator >= (const Fixed& fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator <= (const Fixed& fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator == (const Fixed& fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator != (const Fixed& fixed) const
{
	return !(*this == fixed);
}

const Fixed Fixed::operator + (const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (newFixed);
}

const Fixed Fixed::operator - (const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (newFixed);
}

const Fixed Fixed::operator * (const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits((this->toFloat() * fixed.toFloat()) * (1 << _bits));
	return (newFixed);
}

const Fixed Fixed::operator / (const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits((this->toFloat() / fixed.toFloat()) * (1 << _bits));
	return (newFixed);
}

Fixed& Fixed::operator ++ (void)
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed& Fixed::operator -- (void)
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

// Member functions

Fixed Fixed::min(Fixed& fixed, Fixed& other)
{
	if (fixed < other)
		return (fixed);
	return (other);
}

Fixed Fixed::max(Fixed& fixed, Fixed& other)
{
	if (fixed > other)
		return (fixed);
	return (other);
}

Fixed Fixed::min(const Fixed& fixed, const Fixed& other)
{
	if (fixed < other)
		return (fixed);
	return (other);
}

Fixed Fixed::max(const Fixed& fixed, const Fixed& other)
{
	if (fixed > other)
		return (fixed);
	return (other);
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

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
