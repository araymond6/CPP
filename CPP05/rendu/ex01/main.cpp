#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 56);
		Form document("some important form", 55, 1);

		std::cout << bob << std::endl;
		std::cout << document << std::endl; // Bob and document information.

		bob.signForm(document); // Bob signs the form.

		document.beSigned(bob); // Trying to sign an already signed form.

	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}