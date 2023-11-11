#include "Zombie.hpp"
#include <cstdlib>

int	main(){
	std::string	Z;
	
	system("clear");
	std::cout << "\033[0;32mDeploying Zombie on the heap 🧟\033[0m" << std::endl;
	std::cout << "Enter the Zombie's name: " << std::flush;
	std::cin >> Z;
	Zombie *Z1 = newZombie(Z);
	Z1->announce();
	delete Z1;
	
	std::cout << "\033[0;32m\nDeploying a Zombie on the stack 🧟\033[0m" << std::endl;
	std::cout << "Enter the Zombie's name: " << std::flush;
	std::cin >> Z;
	randomChump(Z);
	return (0);
}
