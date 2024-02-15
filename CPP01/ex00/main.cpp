#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("Carl");
	Zombie *zombie2 = newZombie("Monique");

	zombie1->announce();
	zombie2->announce();
	randomChump("Hollande");

	delete(zombie1);
	delete(zombie2);

	return (0);
}