#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Bobreaucrat")
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	_grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Custom Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << _name << ": Bureaucrat Default Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	bool success;
	try
	{
		success = form.beSigned(*this);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
		return ;
	}
	if (success == false)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cout << "form is already signed." << std::endl;
	}
	else
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";

	return (os);
}