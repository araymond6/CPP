#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <exception>

#define ERROR 1
#define CHAR 2
#define INT 3
#define FLOAT 4
#define DOUBLE 5
#define IMPOSSIBLE 6

typedef std::string::iterator strIt;
using std::endl;

class Conversion
{
	public:
		Conversion(std::string arg);
		Conversion(const Conversion& other);
		~Conversion(void);
		Conversion& operator = (const Conversion& other);

		void toChar(int type);
		void toInt(int type);
		void toFloat(int type);
		void toDouble(int type);

		int findType(void);

	private:
		const std::string _arg;
};