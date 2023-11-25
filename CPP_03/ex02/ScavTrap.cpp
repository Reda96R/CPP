#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "::ScavTrap:: > " << this->name << " is made!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap&	f) : ClapTrap(){
	std::cout << "::ScavTrap:: > Copy constructer is called" << std::endl;
	*this = f;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& f){
	std::cout << "::ScavTrap:: > Copy assignment operator is called" << std::endl;
	if (this != &f){
		this->name = f.name;
		this->hitPoints = f.hitPoints;
		this->energyPoints = f.energyPoints;
		this->attackDamage = f.attackDamage;
	}
	return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "::ScavTrap:: > " << this->name << " is made!" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << "::ScavTrap:: > " << this->name << " is now in Gate keeper mode!" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (this->hitPoints){
		if (this->energyPoints){
			this->energyPoints--;
			std::cout << "::ScavTrap:: > " << this->name << " strikes " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		}
		else
			std::cout << "::ScavTrap:: > " << this->name << "does not have enough energy!" << std::endl;
		return ;
	}
	std::cout << "::ScavTrap:: > " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "::ScavTrap:: > " << this->name << " is demolished!" << std::endl;
}
