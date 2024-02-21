#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		AForm* form;
		Intern intern;
		Bureaucrat bob("Bob", 2);

		form = intern.makeForm("shrubbery creation", "Bob");
		form->beSigned(bob);
		std::cout << *form << std::endl;
		form->execute(bob);
		delete form;

		form = intern.makeForm("RobotomyRequest", "Same Bob");
		form->beSigned(bob);
		std::cout << *form << std::endl;
		form->execute(bob);
		delete form;

		form = intern.makeForm("PresidentialPardon", "Same Bob again");
		form->beSigned(bob);
		std::cout << *form << std::endl;
		form->execute(bob);
		delete form;

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