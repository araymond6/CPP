#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA(std::string name, Weapon const &weapon);
	~HumanA(void);

	void attack(void);

	private:
	Weapon const &_weapon;
	std::string _name;
};