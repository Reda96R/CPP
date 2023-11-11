#include "Zombie.hpp"

Zombie::Zombie(){
}

void	Zombie::initName( std::string name ){
	this->name = name;
}

void	Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << "\033[0;31m" << this->name << " is destroyed \033[0m" << std::endl;
}
