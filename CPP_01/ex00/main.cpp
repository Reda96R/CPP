#include "Zombie.hpp"

int	main(){
	std::string	Z;
	
	std::cout << "Deploying a Zombie on the stack" << std::endl;
	std::cout << "Enter the Zombie's name: " << std::flush;
	std::cin >> Z;
	Zombie	Z1(Z);
}
