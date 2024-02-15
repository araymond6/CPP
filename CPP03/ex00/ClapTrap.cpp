#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("KlapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << _name << ": Default constructor called" << endl;
}

ClapTrap::ClapTrap(std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << _name << ": String constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << endl;
	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << _name << ": Default destructor called" << endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
		this->_name = other._name;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount >= this->_hitPoints && this->_hitPoints > 0)
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " took " << amount << " points of damage!" << endl;
		std::cout << this->_name << " is out of hit points." << endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is out of hit points." << endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << this->_name << " took " << amount << " points of damage!" << endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << this->_name << " has been repaired by " << amount << " points." << endl;

		if (this->_energyPoints == 0)
		{
			std::cout << this->_name << " is out of energy points!" << endl;
		}
	}
	else
	{
		if (this->_energyPoints <= 0 && this->_hitPoints <= 0)
		{
			std::cout << "Cannot repair, " << this->_name << " is out of hit points and energy points." << endl;
		}
		else if (this->_hitPoints <= 0)
		{
			std::cout << "Cannot repair, " << this->_name << " is out of hit points." << endl;
		}
		else
		{
			std::cout << "Cannot repair, " << this->_name << " is out of energy points." << endl;
		}
	}
}

int ClapTrap::getAttackDamage(void)
{
	std::cout << "Getting " << this->_name << "'s attack damage." << endl;
	return (this->_attackDamage);
}