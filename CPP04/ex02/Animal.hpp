#pragma once
#include <iostream>
#include <ostream>
#include <string>

using std::endl;

class Animal
{
	public:
	Animal& operator = (const Animal& other);
	virtual ~Animal(void);

	virtual void makeSound(void) const = 0;
	void printSound(void);
	std::string getType(void) const;

	protected:
	Animal(void);
	Animal(const Animal& other);
	std::string _type;
};