#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap(void);
	ScavTrap(std::string &name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator = (const ScavTrap& other);
	
	void attack(const std::string& target);
	void guardGate(void);
};