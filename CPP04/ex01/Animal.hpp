#pragma once
#include <iostream>
#include <ostream>
#include <string>

using std::endl;

class Animal
{
	public:
	Animal(void);
	Animal(const Animal& other);
	Animal& operator = (const Animal& other);
	virtual ~Animal(void);

	virtual void makeSound(void) const;
	void printSound(void);
	std::string getType(void) const;

	protected:
	std::string _type;
};