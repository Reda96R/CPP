#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "::::::::::Basic test::::::::::" << std::endl;
	std::cout << std::endl;
	// Animal test;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete (i);
	delete (j);

	// std::cout << std::endl;
	// 
	// std::cout << "::::::::::WrongAnimal::::::::::" << std::endl;
	// std::cout << std::endl;
	// const WrongAnimal*	k = new WrongAnimal();
	// const WrongAnimal*	l = new WrongCat();
	// k->makeSound();
	// l->makeSound();
	// delete(k);
	// delete(l);
	
	std::cout << std::endl;
	
	std::cout << "::::::::::Subject test::::::::" << std::endl;	
	std::cout << std::endl;
	const Animal* animals[4] = {new Cat(), new Cat(), new Dog(), new Dog()};
	for (int i = 0; i < 4; i++)
		delete(animals[i]);

	std::cout << std::endl;
	
	std::cout << ":::::::::Deep copy test::::::::" << std::endl;	
	
	std::cout << std::endl;
	
	std::cout << "----first test----" << std::endl;
	const Cat* a = new Cat();
	a->getBrain()->ideas[0] = "Test0";
	a->getBrain()->ideas[1] = "Test1";

	const Cat* b = new Cat (*a);

	std::cout << std::endl;
	
	std::cout << "--->Cat 1 before: " << std::endl;	
	for (int i = 0; i < 2; i++)
		std::cout << a->getBrain()->ideas[i] << std::endl;

	std::cout << "--->Cat 2 before: " << std::endl;	
	for (int i = 0; i < 2; i++)
		std::cout << b->getBrain()->ideas[i] << std::endl;

	a->getBrain()->ideas[0] = "Hello";
	a->getBrain()->ideas[1] = "World";

	std::cout << std::endl;
	std::cout << "--->Cat 1 after: " << std::endl;	
	for (int i = 0; i < 2; i++)
		std::cout << a->getBrain()->ideas[i] << std::endl;

	std::cout << "--->Cat 2 after: " << std::endl;	
	for (int i = 0; i < 2; i++)
		std::cout << b->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;
	delete a;
	delete b;
	std::cout << std::endl;
	std::cout << "----second test----" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
	
	return 0;
}

