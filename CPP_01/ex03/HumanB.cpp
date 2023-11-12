#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL){
}	

void	HumanB::attack(){
	if (this->weapon == NULL || this->weapon->getType() == "")
		std::cout << this->name << " is not armed" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

HumanB::~HumanB(){
	std::cout << "\033[0;31mHumanB: " << this->name << " is destroyed\033[0m" << std::endl; 
}
