#include "Phonebook.hpp"
#include "Contact.hpp"
#include <sstream>

Phonebook::Phonebook(void) : CONTACTLIMIT(8), contactCounter(0)
{
}

Phonebook::~Phonebook(void)
{
}

void Phonebook::setContact(Contact newContact, int index)
{
	this->_contactList[index] = newContact;
}

Contact &Phonebook::getContact(int index)
{
	return (this->_contactList[index]);
}

std::string Phonebook::getString(std::string str)
{
	std::string rtn;

	std::cout << str << std::endl;
	while (std::getline(std::cin, rtn))
	{
		if (rtn.size() != 0)
		{
			break;
		}
	}
	if (std::cin.eof())
		exit(0);
	return (rtn);
}

void Phonebook::addContact(class Phonebook *phonebook)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string firstName = phonebook->getString("Enter first name: ");
	lastName = phonebook->getString("Enter last name: ");
	nickname = phonebook->getString("Enter nickname: ");
	phoneNumber = phonebook->getString("Enter phone number: ");
	darkestSecret = phonebook->getString("Enter darkest secret: ");

	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	phonebook->setContact(newContact, phonebook->contactCounter % phonebook->CONTACTLIMIT);
	phonebook->contactCounter += 1;
}

void Phonebook::printPhonebook(class Phonebook *phonebook)
{
	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" \
	<< std::setw(10) << "First Name" << "|" \
	<< std::setw(10) << "Last Name" << "|" \
	<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < phonebook->contactCounter && i < phonebook->CONTACTLIMIT; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << ((phonebook->getContact(i).getFirstName().size() > 10) ?
			(phonebook->getContact(i).getFirstName().substr(0, 9) + ".") :
			(phonebook->getContact(i).getFirstName())) << "|";
		std::cout << std::setw(10) << ((phonebook->getContact(i).getLastName().size() > 10) ?
			(phonebook->getContact(i).getLastName().substr(0, 9) + ".") :
			(phonebook->getContact(i).getLastName())) << "|";
		std::cout << std::setw(10) << ((phonebook->getContact(i).getNickname().size() > 10) ?
			(phonebook->getContact(i).getNickname().substr(0, 9) + ".") :
			(phonebook->getContact(i).getNickname())) << "|" << std::endl;
	}
	std::cout << std::endl;
}

int Phonebook::getInput(class Phonebook *phonebook)
{
	std::string input;
	int num = 0;
	
	std::cout << "Enter index number of contact to display: " << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input.size() == 1 && (input[0] >= '1' && input[0] <= '8'))
		{
			std::istringstream(input) >> num;
			if (num <= phonebook->contactCounter)
			{
				std::cout << "Index number entered: " << num << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Invalid input." << std::endl;
		}
	}
	if (std::cin.eof())
		exit(0);
	
	return (num);
}

void Phonebook::printContact(class Phonebook *phonebook, int num)
{
	if ((num >= 1 && num <= 8) && num <= phonebook->contactCounter)
	{
		num -= 1;
		std::cout << std::endl;
		std::cout << "First Name: " << phonebook->getContact(num).getFirstName() << std::endl;
		std::cout << "Last Name: " << phonebook->getContact(num).getLastName() << std::endl;
		std::cout << "Nickname: " << phonebook->getContact(num).getNickname() << std::endl;
		std::cout << "Phone Number: " << phonebook->getContact(num).getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << phonebook->getContact(num).getDarkestSecret() << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Invalid input." << std::endl;
	}
}

void Phonebook::searchPhonebook(class Phonebook *phonebook)
{
	if (phonebook->contactCounter == 0)
	{
		std::cout << "No contact found. Add a contact to search it." << std::endl 
			<< "Contact limit: 8" << std::endl;
		return;
	}

	printPhonebook(phonebook);
	int num = getInput(phonebook);
	printContact(phonebook, num);
}

void exitPhonebook(void)
{
	exit(0);
}