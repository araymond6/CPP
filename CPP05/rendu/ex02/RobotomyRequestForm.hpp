#pragma once
#include <iostream>
#include <exception>
#include <ostream>
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
	std::string _target;

	public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm& operator = (const RobotomyRequestForm& other);

	const std::string& getTarget(void) const;
	void executeForm(void) const;
};

std::ostream& operator << (std::ostream& os, const RobotomyRequestForm& other);