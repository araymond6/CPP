#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name = "PhragTrap";
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	std::cout << _name << ": FragTrap Default constructor called" << endl;
}

FragTrap::FragTrap(std::string& name) : ClapTrap(name)
{
	this->_name = name;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	std::cout << _name << ": FragTrap String constructor called" << endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << _name << ": FragTrap Default destructor called" << endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
		this->_name = other._name;
	}
	return (*this);
}

void FragTrap::highFiveGuys(void)
{
	std::cout << this->_name << ": Can I get a high five guys?" << endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing ";
		std::cout << this->_attackDamage << " points of damage!" << endl;
	}
	else
	{
		if (this->_energyPoints == 0)
		{
			std::cout << "Cannot attack, " << this->_name << " is out of energy points." << endl;
		}
		else if (this->_hitPoints == 0)
		{
			std::cout << "Cannot attack, " << this->_name << " is out of hit points." << endl;
		}
		else
		{
			std::cout << "Cannot attack, " << this->_name << " is out of hit points and energy points." << endl;
		}
	}
}
