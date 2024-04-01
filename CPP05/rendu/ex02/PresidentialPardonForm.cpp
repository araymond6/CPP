#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "void";
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	std::cout << "PresidentialPardonForm Custom Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Default Destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

const std::string& PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::executeForm(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator << (std::ostream& os, const PresidentialPardonForm& other)
{
	os << "Form " << other.getName() << " requires grade " << other.getSignGrade() << 
	" to be signed and grade " << other.getExecuteGrade() << " to be executed. Target is " << 
	other.getTarget() << ". " << 
	((other.isSigned() == true) ? "Form is signed. " : "Form is not signed.");

	return (os);
}