#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Form"), _signed(false), _canSign(1), _canExecute(1)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

AForm::AForm(std::string name, const int toSign, const int toExecute) : _name(name), _canSign(toSign), _canExecute(toExecute)
{
	std::cout << "Form Custom Constructor called" << std::endl;
	if (toSign < 1 || toExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (toSign > 150 || toExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& other) : _name("Form"), _signed(false), _canSign(1), _canExecute(1)
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = other;
}

AForm::~AForm(void)
{
	std::cout << "Form Default Destructor called" << std::endl;
}

AForm& AForm::operator = (const AForm& other)
{
	std::cout << "Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		// Nothing to assign.
	}
	return (*this);
}

int AForm::getSignGrade(void) const
{
	return (this->_canSign);
}

int AForm::getExecuteGrade(void) const
{
	return (this->_canExecute);
}

const std::string& AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::isSigned(void) const
{
	return (_signed);
}

bool AForm::beSigned(const Bureaucrat& other)
{
	if (this->isSigned() == true)
	{
		std::cout << "Form " << this->getName() << " is already signed." << std::endl;
		return (false);
	}
	else if (other.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else
	{
		_signed = true;
		return (true);
	}
}

bool AForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else if (this->isSigned() == true && executor.getGrade() <= this->getSignGrade())
	{
		this->executeForm();
		return (true);
	}
	return (false);
}

std::ostream& operator << (std::ostream& os, const AForm& other)
{
	os << "Form " << other.getName() << " requires grade " << other.getSignGrade() << 
	" to be signed and grade " << other.getExecuteGrade() << " to be executed. " << 
	((other.isSigned() == true) ? "Form is signed." : "Form is not signed.");

	return (os);
}