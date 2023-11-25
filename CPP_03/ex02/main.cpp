#include "FragTrap.hpp"

int	main(){
	FragTrap  S0("S0");
	S0.attack("criminal");
	S0.takeDamage(15);
	S0.beRepaired(20);
	S0.highFivesGuys();
	S0.takeDamage(105);
	S0.beRepaired(20);
	return (0);
}
