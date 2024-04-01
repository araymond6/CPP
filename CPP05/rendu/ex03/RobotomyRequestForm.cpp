#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "void";
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm Custom Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Default Destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

const std::string& RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::executeForm(void) const
{
	srand (time(NULL));
	int random = rand() % 2;

	std::cout << "BBBvvvvVVvzzZZzZzTtttT!!!" << std::endl;
	if (random)
	{
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	}
	else
	{
		std::cout << "Failed to robotomize " << this->getTarget() << "." << std::endl;
	}
}

std::ostream& operator << (std::ostream& os, const RobotomyRequestForm& other)
{
	os << "Form " << other.getName() << " requires grade " << other.getSignGrade() << 
	" to be signed and grade " << other.getExecuteGrade() << " to be executed. Target is " << 
	other.getTarget() << ". " << 
	((other.isSigned() == true) ? "Form is signed. " : "Form is not signed.");

	return (os);
}