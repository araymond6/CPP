#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
	Dog(void);
	Dog(const Dog& other);
	Dog& operator = (const Dog& other);
	~Dog(void);

	void makeSound(void) const;

	private:
	Brain* _brain;
};