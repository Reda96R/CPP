#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout<< "**ClapTrap** > " << name << " is deployed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout<< "**ClapTrap** > " << name << " is deployed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap&	f){
	std::cout << "**ClapTrap** >  copy constructer is called" << std::endl;
	*this = f;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& f){
	std::cout << "**ClapTrap** > copy assignment operator is called" << std::endl;
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
			std::cout << "**ClapTrap** > " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		}
		else
			std::cout << "**ClapTrap** > " << this->name << "does not have enough energy!" << std::endl;
		return ;
	}
	std::cout << "**ClapTrap** > " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints){
		if (this->hitPoints > amount){
			this->hitPoints -= amount;
			std::cout << "**ClapTrap** > " << this->name << " takes " << amount << " points of damage!" << std::endl;
		}
		else{
			this->hitPoints = 0;
			std::cout << "**ClapTrap** > " << this->name << " takes " << amount << " points of damage and ";
			std::cout << "\033[0;31mdied!\033[0m" << std::endl;
		}
		return ;
	}
	std::cout << "**ClapTrap** > " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->hitPoints){
		if (this->energyPoints){
			this->hitPoints += amount;
			this->energyPoints--;
			std::cout << "**ClapTrap** > " << name << " repaired itself with " << amount << " points!" << std::endl;
		}
		else
			std::cout << "**ClapTrap** > " << this->name << " does not have enough energy!" << std::endl;
		return ;
	}
	std::cout << "**ClapTrap** > " << this->name << " \033[0;31mis dead!\033[0m" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "**ClapTrap** > " << this->name << " is destroyed" << std::endl;
}
