#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
	this->name = name;
}

void	Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << "\033[0;31m" << this->name << " is destroyed " << std::endl;
}
