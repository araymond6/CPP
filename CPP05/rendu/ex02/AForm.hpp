#pragma once
#include <iostream>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm
{
	private:
	const std::string _name;
	bool _signed;
	const int _canSign;
	const int _canExecute;

	public:
	AForm(void);
	AForm(const AForm& other);
	AForm(std::string name, const int toSign, const int toExecute);
	AForm& operator = (const AForm& other);
	virtual ~AForm(void);

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
	bool execute(const Bureaucrat& other) const;
	virtual void executeForm(void) const = 0;
};

std::ostream& operator << (std::ostream& os, const AForm& other);