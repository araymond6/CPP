#pragma once
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap(void);
	FragTrap(std::string &name);
	~FragTrap(void);
	FragTrap(const FragTrap& other);
	FragTrap& operator = (const FragTrap& other);

	void attack(const std::string& target);
	void highFiveGuys(void);
};