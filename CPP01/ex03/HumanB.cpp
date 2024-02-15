#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void)
{
	if (_weapon)
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
	std::cout << this->_name << " attacks with their bare fists" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}