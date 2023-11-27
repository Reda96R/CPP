#include "Animal.hpp"

Animal::Animal(){
	std::cout << this->type << " constructer called" << std::endl;
}

Animal::Animal(std::string type){
	std::cout << this->type << " constructer called" << std::endl;
}

Animal::Animal(const Animal& f){
	std::cout << this->type << " copy constructer called" << std::endl;
	*this = f;
}

Animal&  Animal::operator=(const Animal& rhs){
	std::cout << this->type << " copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

//add makeSound

std::string	  Animal::getType() const{
	return (this->type);
}

Animal::~Animal(){
	std::cout << this->type << " destructor called" << std::endl;
}
