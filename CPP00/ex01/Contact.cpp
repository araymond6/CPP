#include "Contact.hpp"
#include "Phonebook.hpp"

Contact::Contact(std::string fName, std::string lName, std::string nname, std::string pNumber, std::string dSecret) : 
		firstName(fName), lastName(lName), nickname(nname), phoneNumber(pNumber), darkestSecret(dSecret)
{
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string &Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string &Contact::getLastName(void)
{
	return (this->lastName);
}

std::string &Contact::getNickname(void)
{
	return (this->nickname);
}

std::string &Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

std::string &Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}