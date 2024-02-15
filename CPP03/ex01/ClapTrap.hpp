#pragma once
#include <iostream>
#include <ostream>

using std::endl;

class ClapTrap
{
	public:
	ClapTrap(void);
	ClapTrap(std::string &name);
	virtual ~ClapTrap(void);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator = (const ClapTrap& other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int getAttackDamage(void);

	protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};