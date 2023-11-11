#include "Zombie.hpp"
#include <cstdlib>

int	main(){
	int	N = 3;
	
	system("clear");
	if (N <= 0)
		return (0);
	Zombie *Z = zombieHorde(N, "Ztest");
	for (int i = 0; i < N; i++)
		Z[i].announce();
	delete [] Z;
	return (0);
}
