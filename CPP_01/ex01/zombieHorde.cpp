#include "Zombie.hpp" 

Zombie*	  zombieHorde ( int N, std::string name ){
	if (N <= 0)
		return (NULL);
	Zombie	*Z = new Zombie[N];
	for (int n = 0; n < N; n++)
		Z[n].initName(name);
	return (Z);
}
