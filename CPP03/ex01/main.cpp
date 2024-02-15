#include "ScavTrap.hpp"

int main( void ) 
{
	std::string s1 = "Gilles";
	std::string s2 = "Thérèse";

	ClapTrap c1(s1);
	ScavTrap c2(s2);

	std::cout << endl;

	c1.attack(s2);
	c2.takeDamage(c1.getAttackDamage());
	c2.attack(s1);
	c1.takeDamage(c2.getAttackDamage());
	c2.beRepaired(5);
	c2.guardGate();

	std::cout << endl;

	return (0);
}