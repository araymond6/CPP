#pragma once
#include "Animal.hpp"

class WrongAnimal
{
	public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator = (const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	void makeSound(void) const;
	std::string getType(void) const;

	protected:
	std::string _type;
};