#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "::::::::::Animal::::::::::" << std::endl;
	const Animal* meta = new Animal();
	// (void) meta;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// (void) j;
	// (void) i;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete (i);
	delete (j);
	delete (meta);

	std::cout << "\n::::::::::WrongAnimal::::::::::" << std::endl;
	const WrongAnimal*	k = new WrongAnimal();
	const WrongAnimal*		l = new WrongCat();
	std::cout << "Wrong Animal: " << k->getType() << std::endl;
	std::cout << "Wrong Cat: " << l->getType() << std::endl;
	k->makeSound();
	l->makeSound();
	delete(k);
	delete(l);
	return 0;
}

