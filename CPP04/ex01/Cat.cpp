#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat Default constructor called" << endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat Default destructor called" << endl;
	delete this->_brain;
}

Cat& Cat::operator = (const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_type = other._type;
		if (this->_brain)
		{
			delete this->_brain;
			_brain = NULL;
		}
		if (other._brain)
		{
			this->_brain = new Brain();
			for (int i = 0; i < IDEACOUNT; i++)
			{
				this->_brain[i] = other._brain[i];
			}
		}
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "*mewmew*" << endl;
}