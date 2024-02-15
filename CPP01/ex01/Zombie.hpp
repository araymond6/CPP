#pragma once
#include <iostream>

class Zombie
{
	public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);

	void announce(void);
	void setName(std::string name);

	private:
	std::string _name;

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);