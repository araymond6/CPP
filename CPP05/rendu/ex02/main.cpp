#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Rénald", 4);

		ShrubberyCreationForm shrubberyform("Rénald");
		std::cout << shrubberyform << std::endl;
		shrubberyform.beSigned(bob);
		shrubberyform.execute(bob);

		RobotomyRequestForm robotform("Rénald");
		std::cout << robotform << std::endl;
		robotform.beSigned(bob);
		robotform.execute(bob);

		PresidentialPardonForm prezform("Rénald");
		std::cout << prezform << std::endl;
		prezform.beSigned(bob);
		prezform.execute(bob);

		bob.executeForm(shrubberyform);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}