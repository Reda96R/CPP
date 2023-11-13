#include "Harl.hpp"

Harl::Harl(){
}

void	Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(){
	std::cout << " cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level){
	void (Harl::*levels[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levelsS[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++){
		if (level == levelsS[i]){
			(this->*levels[i])();
			return ;
		}
	}
	std::cout << "\033[0;31mError: Invalide level\033[0m" << std::endl;
}

Harl::~Harl(){
}
