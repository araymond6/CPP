#pragma once
#include <iostream>
#include <exception>
#include <ostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
	std::string _target;

	public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& other);

	const std::string& getTarget(void) const;
	void executeForm(void) const;
};

std::ostream& operator << (std::ostream& os, const ShrubberyCreationForm& other);