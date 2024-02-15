#pragma once
#include <iostream>
#include <exception>
#include <ostream>

class AForm;

class Bureaucrat
{
	private:
	std::string _name;
	int _grade;

	public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);
	Bureaucrat& operator = (const Bureaucrat& other);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual char const* what() const throw() { return ("Bureaucrat: Grade too high."); };
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual char const* what() const throw() { return ("Bureaucrat: Grade too low."); };
	};

	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm& form);
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& other);