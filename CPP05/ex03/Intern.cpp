#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = other;
}

Intern::~Intern(void)
{
	std::cout << "Intern Default Destructor called" << std::endl;
}

Intern& Intern::operator = (const Intern& other)
{
	std::cout << "Intern Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		// nothing to assign
	}
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string ar[6] = {"ShubberyCreation", "RobotomyRequest", "PresidentialPardon", "shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 6; i++)
	{
		if (ar[i] == formName)
		{
			switch (i % 3)
			{
				case 0:
				{
					AForm* shrubform = new ShrubberyCreationForm(target);
					return (shrubform);
				}
				case 1:
				{
					AForm* robotomyform = new RobotomyRequestForm(target);
					return (robotomyform);
				}
				case 2:
				{
					AForm* pardonform = new PresidentialPardonForm(target);
					return (pardonform);
				}
			}
		}
	}
	std::cout << "Form name not found." << std::endl;
	return (NULL);
}