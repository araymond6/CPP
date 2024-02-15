#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default constructor called" << endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy constructor called" << endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Brain Default destructor called" << endl;
}

Brain& Brain::operator = (const Brain& other)
{
	std::cout << "Brain Copy assignment operator called" << endl;
	if (this != &other)
	{
		for (int i = 0; i < IDEACOUNT; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}