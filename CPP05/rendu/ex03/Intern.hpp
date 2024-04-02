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

	typedef AForm* (Intern::*functionPointer)(std::string target);
	AForm* makeForm(std::string formName, std::string target);
	AForm* makeShrubbery(std::string target);
	AForm* makeRobotomy(std::string target);
	AForm* makePresidential(std::string target);
};