#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "void";
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm Custom Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Default Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

const std::string& ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::executeForm(void) const
{
	std::string fileName = _target;
	fileName.append("_shrubbery");
	std::ofstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open file" << std::endl;
		return ;
	}

	file << std::setw(5) << "^" << std::endl;
	file << std::setw(6) << "/ \\" << std::endl;
	file << std::setw(7) << "/   \\" << std::endl;
	file << std::setw(8) << "/     \\" << std::endl;
	file << std::setw(5) << "|" << std::endl;
	file << std::setw(5) << "|" << std::endl;
	file << std::endl;
	file << std::setw(5) << "^" << std::endl;
	file << std::setw(6) << "/ \\" << std::endl;
	file << std::setw(7) << "/   \\" << std::endl;
	file << std::setw(8) << "/__ __\\" << std::endl;
	file << std::setw(5) << "|" << std::endl;
	file << std::setw(5) << "|" << std::endl;

	file.close();
}

std::ostream& operator << (std::ostream& os, const ShrubberyCreationForm& other)
{
	os << "Form " << other.getName() << " requires grade " << other.getSignGrade() << 
	" to be signed and grade " << other.getExecuteGrade() << " to be executed. Target is " << 
	other.getTarget() << ". " << 
	((other.isSigned() == true) ? "Form is signed. " : "Form is not signed.");

	return (os);
}