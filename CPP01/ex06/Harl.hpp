#include <iostream>
#include <string>
#define DEBUGSTR "DEBUG"
#define INFOSTR "INFO"
#define WARNINGSTR "WARNING"
#define ERRORSTR "ERROR"
#define COMPLAINSTR "[ Probably complaining about insignificant problems ]"

class Harl
{
	public:
	Harl(void);
	~Harl(void);

	typedef enum complaint
	{
		DEBUG = 0,
		INFO,
		WARNING,
		ERROR,
		OTHER
	}	t_complaint;
	
	typedef void (Harl::*functionPointer)(void); // array of pointers to Harl member functions
	int getComplaint(std::string level);
	void complain(int level);
	void callFunction(void (Harl::*f)(void));

	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};