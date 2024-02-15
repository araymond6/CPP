#pragma once
#include <iostream>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm //TODO: Make class actually abstract, create new files 
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
	~AForm(void);
	AForm& operator = (const AForm& other);

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

std::ostream& operator << (std::ostream& os, const AForm& other);