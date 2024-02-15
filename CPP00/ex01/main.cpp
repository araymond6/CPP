#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::string input;
	std::string add = "ADD";
	std::string search = "SEARCH";
	std::string exitPb = "EXIT";
	class Phonebook phonebook;
	
	std::cout << "Welcome to the world's worst phonebook!" << std::endl;
	std::cout << "Select an option: 'ADD', 'SEARCH', 'EXIT'." << std::endl;
	while (std::getline(std::cin, input))
	{	
		if (input.compare(add) == 0)
		{
			phonebook.addContact(&phonebook);
		}
		else if (input.compare(search) == 0)
		{
			phonebook.searchPhonebook(&phonebook);
		}
		else if (input.compare(exitPb) == 0)
		{
			exitPhonebook();
		}
		else
		{
			std::cout << "Invalid option." << std::endl;
		}
		std::cout << "Select an option: 'ADD', 'SEARCH', 'EXIT'." << std::endl;
	}

	return (0);
}