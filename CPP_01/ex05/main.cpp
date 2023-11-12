#include "Harl.hpp"

int	main(){
	std::string	input;
	Harl		Harl;
	do {
		std::cout << "Enter a level: ";
		std::cin >> input;
		Harl.complain(input);
	}
	while (input.compare("exit") && std::cin.good());
	return (0);
}
