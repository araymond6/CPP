#include "whatever.hpp"

int main()
{
	std::string a = "mario", b = "kart";
    std::cout << "min: " << ::min(a, b) << std::endl;
    std::cout << "max: " << ::max(a, b) << std::endl;
    std::cout << "before swap: " << a << " " << b << std::endl;
    ::swap(a, b);
    std::cout << "after swap: " << a << " " << b << std::endl;

    return (0);
}