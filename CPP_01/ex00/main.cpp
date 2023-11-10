#include "Zombie.hpp"
#include <cstdlib>
int	main(){
	std::string	Z;
	
	system("clear");
	std::cout << "\033[0;32mDeploying Zombie on the heap\033[0m" << std::endl;
	std::cout << "Enter the Zombie's name: " << std::flush;
	std::cin >> Z;
	Zombie *Z2 = newZombie(Z);
	Z2->announce();
	delete Z2;
	
	std::cout << "\033[0;32mCalling randomChump\033[0m" << std::endl;
	std::cout << "Enter the Zombie's name: " << std::flush;
	std::cin >> Z;
	randomChump(Z);
	return (0);
}
