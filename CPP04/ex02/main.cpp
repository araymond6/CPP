#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() // make a tableau of animals half dogs half cats
{
	Animal* a[10];


	for (int i = 0; i < 5; i++) // creating array of animals, half cats and half dogs
	{
		a[i] = new Cat();
	}
	for (int i = 5; i < 10; i++)
	{
		a[i] = new Dog();
	}

	for (int i = 0; i < 10; i++) // announce()
	{
		std::cout << a[i]->getType() << endl;
		a[i]->makeSound();
	}

	for (int i = 9; i >= 0; i--) // freeing the animals and their brains
	{
		delete a[i];
	}

	// This is all good and works, but what if
	// we try to instantiate an animal?

	// const Animal* meta = new Animal();

	// Making the constructor protected or private makes it so a constructor
	// cannot be called for the Animal class, as it is unavailable.

	return (0);
}