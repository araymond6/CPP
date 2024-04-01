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

	typedef AForm* (Intern::*functionPointer)(void);
	AForm* makeForm(std::string formName, std::string target);
	AForm* Intern::makeShrubbery(std::string target);
	AForm* Intern::makeRobotomy(std::string target);
	AForm* Intern::makePresidential(std::string target);
};