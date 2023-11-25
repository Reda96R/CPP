#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "--FragTrap-- > " << this->name << " is alive!" << std::endl;
}

FragTrap::FragTrap(const FragTrap&	f) : ClapTrap(){
	std::cout << "--FragTrap-- > Copy constructer is called" << std::endl;
	*this = f;
}

FragTrap& FragTrap::operator=(const FragTrap& f){
	std::cout << "--FragTrap-- > Copy assignment operator is called" << std::endl;
	if (this != &f){
		this->name = f.name;
		this->hitPoints = f.hitPoints;
		this->energyPoints = f.energyPoints;
		this->attackDamage = f.attackDamage;
	}
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "--FragTrap-- > " << this->name << " is alive!" << std::endl;
}

void	FragTrap::attack(const std::string& target){
	if (this->hitPoints){
		if (this->energyPoints){
			this->energyPoints--;
			std::cout << "--FragTrap-- > " << this->name << " injured " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		}
		else
			std::cout << "--FragTrap-- > " << this->name << "does not have enough energy!" << std::endl;
		return ;
	}
	std::cout << "--FragTrap-- > " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
}

void	FragTrap::highFivesGuys(){
	std::cout << "--FragTrap-- > " << this->name << " high five guys 🖐️" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "--FragTrap-- > " << this->name << " is gone" << std::endl;
}
