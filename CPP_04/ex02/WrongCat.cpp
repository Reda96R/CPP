#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "🐈 " << this->type << " constructer called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& f) : WrongAnimal("WrongCat"){
	std::cout << "🐈 " << this->type << " copy constructer called" << std::endl;
	*this = f;
}

WrongCat&  WrongCat::operator=(const WrongCat& rhs){
	std::cout << "🐈 " << this->type << " copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound() const{
	std::cout << "🐈 Meow!" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "🐈 " << this->type << " destructor called" << std::endl;
}
