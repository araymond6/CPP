#pragma once
#include <iostream>
#include <exception>
#include <ostream>

class Bureaucrat;

class Form
{
	private:
	const std::string _name;
	bool _signed;
	const int _canSign;
	const int _canExecute;

	public:
	Form(void);
	Form(const Form& other);
	Form(std::string name, const int toSign, const int toExecute);
	~Form(void);
	Form& operator = (const Form& other);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual char const* what() const throw() { return ("Form: Grade too high."); };
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual char const* what() const throw() { return ("Form: Grade too low."); };
	};

	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	const std::string& getName(void) const;
	bool isSigned(void) const;
	bool beSigned(const Bureaucrat& other);
	bool beExecuted(const Bureaucrat& other);
};

std::ostream& operator << (std::ostream& os, const Form& other);