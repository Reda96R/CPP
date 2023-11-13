#include "Harl.hpp"

int	main(){
	std::string	input;
	Harl		Harl;

	system("clear");
	do {
		std::cout << "\033[0;32mEnter a level: \033[0m";
		std::cin >> input;
		Harl.complain(input);
	}
	while (input.compare("exit") && std::cin.good());
	return (0);
}
