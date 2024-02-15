#include <iostream>
#include <string>
#define DEBUGSTR "DEBUG"
#define INFOSTR "INFO"
#define WARNINGSTR "WARNING"
#define ERRORSTR "ERROR"

class Harl
{
	public:
	Harl(void);
	~Harl(void);
	
	void complain(std::string level);
	void callFunction(void (Harl::*f)(void));
	typedef void (Harl::*functionPointer)(void); // array of pointers to Harl member functions

	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};