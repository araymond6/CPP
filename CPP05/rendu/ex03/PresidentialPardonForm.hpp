#pragma once
#include <iostream>
#include <exception>
#include <ostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
	std::string _target;

	public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm& operator = (const PresidentialPardonForm& other);

	const std::string& getTarget(void) const;
	void executeForm(void) const;
};

std::ostream& operator << (std::ostream& os, const PresidentialPardonForm& other);