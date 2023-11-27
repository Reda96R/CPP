
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << this->type << "WrongAnimal constructer called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
	std::cout << "WrongAnimal constructer called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& f){
	std::cout << "WrongAnimal copy constructer called" << std::endl;
	*this = f;
}

WrongAnimal&  WrongAnimal::operator=(const WrongAnimal& rhs){
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string	  WrongAnimal::getType() const{
	return (this->type);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}
