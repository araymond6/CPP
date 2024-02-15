#include "Zombie.hpp"

int main(void)
{
	int n = 6;
	
	Zombie *horde = zombieHorde(n, "Bob");
	if (!horde)
	{
		exit(0);
	}

	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	
	return (0);
}
