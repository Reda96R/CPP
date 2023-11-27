#include "Animal.hpp"

Animal::Animal(){
	std::cout << this->type << "Animal constructer called" << std::endl;
}

Animal::Animal(std::string type) : type(type){
	std::cout << "Animal constructer called" << std::endl;
}

Animal::Animal(const Animal& f){
	std::cout << "Animal copy constructer called" << std::endl;
	*this = f;
}

Animal&  Animal::operator=(const Animal& rhs){
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	Animal::makeSound() const{
	std::cout << "Animal makeSound called" << std::endl;
}

std::string	  Animal::getType() const{
	return (this->type);
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}
