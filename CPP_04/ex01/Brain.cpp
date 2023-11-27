#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain::Brain(const Brain& f){
	*this = f;
}

Brain& Brain::operator=(const Brain& rhs){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}
