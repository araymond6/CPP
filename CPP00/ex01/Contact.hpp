#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	public:
	Contact(void); // default constructor for building the array in phonebook
	Contact(std::string firstName, std::string lastName,
		std::string nickname, std::string phoneNumber,
		std::string darkestSecret); // constructor for when the information on the contact is known
	~Contact(void);

	std::string &getFirstName(void);
	std::string &getLastName(void);
	std::string &getNickname(void);
	std::string &getPhoneNumber(void);
	std::string &getDarkestSecret(void);

	private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif