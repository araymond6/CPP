#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Form"), _signed(false), _canSign(1), _canExecute(1)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, const int toSign, const int toExecute) : _name(name), _canSign(toSign), _canExecute(toExecute)
{
	std::cout << "Form Custom Constructor called" << std::endl;
	if (toSign < 1 || toExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (toSign > 150 || toExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& other) : _name("Form"), _signed(false), _canSign(1), _canExecute(1)
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = other;
}

Form::~Form(void)
{
	std::cout << "Form Default Destructor called" << std::endl;
}

Form& Form::operator = (const Form& other)
{
	std::cout << "Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		// Nothing to assign.
	}
	return (*this);
}

int Form::getSignGrade(void) const
{
	return (this->_canSign);
}

int Form::getExecuteGrade(void) const
{
	return (this->_canExecute);
}

const std::string& Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (_signed);
}

bool Form::beSigned(const Bureaucrat& other)
{
	if (this->isSigned() == true)
	{
		std::cout << "Form is already signed." << std::endl;
		return (false);
	}
	else if (other.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else
	{
		_signed = true;
		return (true);
	}
}

bool Form::beExecuted(const Bureaucrat& other)
{
	if (other.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	return (true);
}

std::ostream& operator << (std::ostream& os, const Form& other)
{
	os << "Form " << other.getName() << " requires grade " << other.getSignGrade() << 
	" to be signed and grade " << other.getExecuteGrade() << " to be executed. " << 
	((other.isSigned() == true) ? "Form is signed." : "Form is not signed.");

	return (os);
}