#include "Fixed.hpp"

int main( void ) 
{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << endl;
std::cout << ++a << endl;
std::cout << a << endl;
std::cout << a++ << endl;
std::cout << a << endl;
std::cout << b << endl;
std::cout << Fixed::max( a, b ) << std::endl;

return 0;
}