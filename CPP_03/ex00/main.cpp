#include "ClapTrap.hpp"

int	main(){
	ClapTrap  t0("t0");
	t0.attack("t0_target");
	t0.takeDamage(5);
	t0.beRepaired(4);
	t0.beRepaired(1);
	t0.takeDamage(10);
	t0.beRepaired(10);
	return (0);
}
