#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name = "ZcavTrap";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << _name << ": ScavTrap Default constructor called" << endl;
}

ScavTrap::ScavTrap(std::string& name) : ClapTrap(name)
{
	this->_name = name;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << _name << ": ScavTrap String constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << _name << ": ScavTrap Default destructor called" << endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
		this->_name = other._name;
	}
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " has entered gatekeeper mode." << endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "Scavtrap " << _name << " attacks " << target << ", causing ";
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
