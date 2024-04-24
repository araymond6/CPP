#include <iostream>
#include <exception>

template<class T>
class Array
{
	public:

		Array(void);
		Array(unsigned int uint);
		Array(const Array& other);
		~Array(void);
		Array& operator = (const Array& other);

		unsigned int size(void) const;

	private:

		T *_array;
};