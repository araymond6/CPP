#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
	Cat(void);
	Cat(const Cat& other);
	Cat& operator = (const Cat& other);
	~Cat(void);

	void makeSound(void) const;

	private:
	Brain* _brain;
};