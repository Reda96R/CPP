#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "🐈 " << this->type << " constructer called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& f) : Animal("Cat"){
	std::cout << "🐈 " << this->type << " copy constructer called" << std::endl;
	*this = f;
}

Cat&  Cat::operator=(const Cat& rhs){
	std::cout << "🐈 " << this->type << " copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "🐈 Meow!" << std::endl;
}

Brain*	Cat::getBrain() const{
	return (this->brain);
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "🐈 " << this->type << " destructor called" << std::endl;
}
