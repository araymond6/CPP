#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

void exitPhonebook(void);

class Phonebook
{
	public:
	Phonebook(void);
	~Phonebook(void);

	void setContact(Contact newContact, int index);
	void addContact(class Phonebook *phonebook);
	class Contact &getContact(int index);
	void printPhonebook(class Phonebook *phonebook);
	int getInput(class Phonebook *phonebook);
	void printContact(class Phonebook *phonebook, int num);
	void searchPhonebook(class Phonebook *phonebook);
	std::string getString(std::string str);

	private:
	class Contact _contactList[8];
	const int CONTACTLIMIT;
	int contactCounter;
};

#endif