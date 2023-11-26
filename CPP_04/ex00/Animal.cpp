#include "Animal.hpp"

Animal::Animal() : type("Animal"){
	std::cout << this->type << " constructer called" << std::endl;
}

Animal::Animal(std::string type) : type(type){
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

Animal::~Animal(){
	std::cout << this->type << " destructor called" << std::endl;
}

// void	Animal::getType() const{
// 	return (this->type);
// }
