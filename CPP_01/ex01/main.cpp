#include "Zombie.hpp"
#include <cstdlib>

int	main(){
	int	N = 0;
	
	system("clear");
	Zombie *Z = zombieHorde(N, "Ztest");
	for (int i = 0; i < N; i++)
		Z[i].announce();
	delete [] Z;
	return (0);
}
