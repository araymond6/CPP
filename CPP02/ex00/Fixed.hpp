#include <iostream>
#include <ostream>

using std::endl;

class Fixed
{
    public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed& fixed);
    void operator = (const Fixed& fixed);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    private:
    static const int _bits = 8;
    int _fixed;
};