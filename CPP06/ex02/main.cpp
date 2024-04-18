#include "Base.hpp"

Base *generate(void)
{
	int random;
	srand(time(NULL));
	random = rand() % 3;
	
	if (random == 0)
	{
		Base *newA = new A();
		return (newA);
	}
	else if (random == 1)
	{
		Base *newB = new B();
		return (newB);
	}
	else
	{
		Base *newC = new C();
		return (newC);
	}
}

void identify(Base* p)
{
	A *ra = dynamic_cast<A*>(p);
	B *rb = dynamic_cast<B*>(p);
	C *rc = dynamic_cast<C*>(p);

	if (ra)
		std::cout << "Base* is of type A" << std::endl;
	if (rb)
		std::cout << "Base* is of type B" << std::endl;
	if (rc)
		std::cout << "Base* is of type C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &ra = dynamic_cast<A&>(p);
		(void)ra;
		std::cout << "Base& is of type A" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Base& is NOT of type A" << std::endl;
	}

	try
	{
		B &rb = dynamic_cast<B&>(p);
		(void)rb;
		std::cout << "Base& is of type B" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Base& is NOT of type B" << std::endl;
	}

	try
	{
		C &rc = dynamic_cast<C&>(p);
		(void)rc;
		std::cout << "Base& is of type C" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Base& is NOT of type C" << std::endl;
	}
}

int main()
{
	Base* newBase = generate();

	identify(newBase);
	identify(*newBase);
	
	delete newBase;
	return (0);
}