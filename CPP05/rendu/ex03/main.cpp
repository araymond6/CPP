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
		Intern intern;
		Bureaucrat bob("Bob", 2);

		AForm* aform = intern.makeForm("shrubbery creation", "Bob");
		aform->beSigned(bob);
		std::cout << *aform << std::endl;
		aform->execute(bob);
		delete aform;

		// AForm* bform = intern.makeForm("RobotomyRequest", "Same Bob");
		// bform->beSigned(bob);
		// std::cout << *bform << std::endl;
		// bform->execute(bob);
		// delete bform;

		// AForm* cform = intern.makeForm("PresidentialPardon", "Same Bob again");
		// cform->beSigned(bob);
		// std::cout << *cform << std::endl;
		// cform->execute(bob);
		// delete cform;

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