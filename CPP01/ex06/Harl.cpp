#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

int Harl::getComplaint(std::string level)
{
	std::string strstr[] = {DEBUGSTR, INFOSTR, WARNINGSTR, ERRORSTR};
	int arrayLength = sizeof(strstr) / sizeof(std::string);

	for (int i = 0; i < arrayLength; i++)
	{
		if (level.compare(strstr[i]) == 0)
		{
			return (i);
		}
	}
	return (OTHER);
}

void Harl::complain(int level)
{
	functionPointer fP[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch(level)
	{
		case DEBUG:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			callFunction(fP[DEBUG]);
			std::cout << std::endl;
		}
		case INFO:
		{
			std::cout << "[ INFO ]" << std::endl;
			callFunction(fP[INFO]);
			std::cout << std::endl;
		}
		case WARNING:
		{
			std::cout << "[ WARNING ]" << std::endl;
			callFunction(fP[WARNING]);
			std::cout << std::endl;
		}
		case ERROR:
		{
			std::cout << "[ ERROR ]" << std::endl;
			callFunction(fP[ERROR]);
			std::cout << std::endl;
			break;
		}
		case OTHER:
		{
			std::cout << COMPLAINSTR << std::endl;
		}
	}
}

void Harl::callFunction(void (Harl::*f)(void))
{
	(this->*f)();
}

void Harl::debug(void)
{
	std::string debugString = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !";

	std::cout << debugString << std::endl;
}

void Harl::info(void)
{
	std:: string infoString = "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !";

	std::cout << infoString << std::endl;
}

void Harl::warning(void)
{
	std:: string warningString = "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.";

	std::cout << warningString << std::endl;
}

void Harl::error(void)
{
	std::string errorString = "This is unacceptable ! I want to speak to the manager now.";

	std::cout << errorString << std::endl;
}