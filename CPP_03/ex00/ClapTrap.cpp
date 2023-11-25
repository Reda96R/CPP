#include "ClapTrap.hpp"
#include <ostream>

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout<< "ClapTrap " << name << " is deployed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap&	f){
	std::cout << "ClapTrap copy constructer is called" << std::endl;
	*this = f;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& f){
	std::cout << "ClapTrap copy assignment operator is called" << std::endl;
	if (this != &f){
		this->name = f.name;
		this->hitPoints = f.hitPoints;
		this->energyPoints = f.energyPoints;
		this->attackDamage = f.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target){
	if (this->hitPoints){
		if (this->energyPoints){
			this->energyPoints--;
			std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		}
		else
			std::cout << "ClapTrap " << this->name << "does not have enough energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints){
		if (this->hitPoints >= amount)
			this->hitPoints -= amount;
		//handle the case where amount > hitpoints
		std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;
		if (!this->hitPoints)
			std::cout << "ClapTrap " << this->name << " \033[0;31mdied!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints > 0 && this->hitPoints > 0){
		if (this->energyPoints + amount > 10)
			std::cout << "ClapTrap " << this->name << " already reached maximum hitpoints!" << std::endl;
		else{
			this->hitPoints += amount;
			this->energyPoints--;
			std::cout << "ClapTrap " << name << " repaired itself in exchange of " << amount << " hit points!" << std::endl;
		}
		return ;
	}
	if (this->hitPoints <= 0){
		std::cout << "ClapTrap " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " does not have enough energy!" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->name << " is destroyed" << std::endl;
}
