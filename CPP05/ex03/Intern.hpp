#pragma once
#include <iostream>
#include <exception>
#include <ostream>

class AForm;

class Intern
{
	public:
	Intern(void);
	Intern(const Intern& other);
	~Intern(void);
	Intern& operator = (const Intern& other);

	AForm* makeForm(std::string formName, std::string target);
};