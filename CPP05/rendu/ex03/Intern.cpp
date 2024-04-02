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

AForm* Intern::makeShrubbery(std::string target)
{
	AForm* shrubform = new ShrubberyCreationForm(target);
	std::cout << "Intern creates Shrubbery Creation Form." << std::endl;
	return (shrubform);
}

AForm* Intern::makeRobotomy(std::string target)
{
	AForm* robotform = new RobotomyRequestForm(target);
	std::cout << "Intern creates Robotomy Request Form." << std::endl;
	return (robotform);
}

AForm* Intern::makePresidential(std::string target)
{
	AForm* prezform = new PresidentialPardonForm(target);
	std::cout << "Intern creates Presidential Pardon Form." << std::endl;
	return (prezform);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string ar[6] = {"ShubberyCreation", "RobotomyRequest", "PresidentialPardon", 
						"shrubbery creation", "robotomy request", "presidential pardon"};
	functionPointer fP[] = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

	for (int i = 0; i < 6; i++)
	{
		if (ar[i] == formName)
		{
			AForm* form = (this->*fP[i%3])(target);
			return (form);
		}
	}

	std::cout << "Form couldn't be found." << std::endl;
	return (NULL);
}