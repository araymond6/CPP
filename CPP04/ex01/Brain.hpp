#pragma once
#include "Animal.hpp"
#define IDEACOUNT 100

class Brain
{
	public:
	Brain(void);
	Brain(const Brain& other);
	Brain& operator = (const Brain& other);
	~Brain(void);

	std::string ideas[IDEACOUNT];
};