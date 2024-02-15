#include "ClapTrap.hpp"

int main( void ) 
{
	std::string s1 = "Bob";
	std::string s2 = "Thérèse";

	ClapTrap c1(s1);
	ClapTrap c2(s2);

	std::cout << endl;

	c1.beRepaired(5);
	c1.attack(s2);
	c2.takeDamage(c1.getAttackDamage());
	c2.attack(s2);
	c2.takeDamage(c2.getAttackDamage());
	c2.beRepaired(50);

	std::cout << endl;

	return (0);
}