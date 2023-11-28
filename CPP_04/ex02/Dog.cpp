#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "🐕 " << this->type << " constructer called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& f) : Animal("Dog"){
	std::cout << "🐕 " << this->type << " copy constructer called" << std::endl;
	*this = f;
}

Dog&  Dog::operator=(const Dog& rhs){
	std::cout << "🐕 " << this->type << " copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*rhs.brain); 
	}
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << "🐕 Woof!" << std::endl;
}

Brain*	Dog::getBrain() const{
	return (this->brain);
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "🐕 " << this->type << " destructor called" << std::endl;
}
