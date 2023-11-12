#include "HumanA.hpp"

HumanA::HumanA(std::string name,  Weapon& weapon) : name(name), weapon(weapon){
}

void	HumanA::attack(){
	if (this->weapon.getType() == "")
		std::cout << this->name << " is not armed" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon){
	this->weapon = weapon;
}

HumanA::~HumanA(){
	std::cout << "\033[0;31mHumanA: " << this->name << " is destroyed\033[0m" << std::endl; 
}
