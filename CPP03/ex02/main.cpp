#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) 
{
	std::string s1 = "Jacques";
	std::string s2 = "Thérèse";
	std::string s3 = "Gilbert";

	ClapTrap c1(s1);
	ScavTrap c2(s2);
	FragTrap c3(s3);

	std::cout << endl;

	c1.attack(s2);
	c2.takeDamage(c1.getAttackDamage());
	c2.attack(s1);
	c1.takeDamage(c2.getAttackDamage());
	c2.beRepaired(5);
	c3.attack(s2);
	c2.takeDamage(c3.getAttackDamage());
	c2.attack(s3);
	c3.takeDamage(c2.getAttackDamage());
	c2.guardGate();
	c3.highFiveGuys();

	std::cout << endl;

	return (0);
}