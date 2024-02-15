#include <iostream>
#include <ostream>
#include <cmath>

using std::endl;

class Fixed
{
    public:
    Fixed(void);
    Fixed(const Fixed& fixed);
    Fixed(const int raw);
    Fixed(const float fl);
    ~Fixed(void);

    void operator = (const Fixed& fixed);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

    private:
    static const int _bits = 8;
    int _fixed;
};

std::ostream& operator << (std::ostream& os, const Fixed &fixed);