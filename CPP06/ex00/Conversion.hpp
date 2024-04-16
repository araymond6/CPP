#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <cmath>
#include <exception>
#include <sstream>
#include <limits>

#define ERROR 1
#define CHAR 2
#define INT 3
#define FLOAT 4
#define DOUBLE 5
#define IMPOSSIBLE 6

typedef std::string::iterator strIt;
using std::endl;
using std::cout;
using std::to_string;

class Conversion
{
	public:
		Conversion(std::string arg);
		Conversion(const Conversion& other);
		~Conversion(void);
		Conversion& operator = (const Conversion& other);

		void toChar(char c);
		void toInt(int i);
		void toFloat(float f);
		void toDouble(double d);

		void convert(int type);
		int findType(void);

	private:
		const std::string _arg;

};