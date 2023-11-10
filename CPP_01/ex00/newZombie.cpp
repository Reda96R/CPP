#include "Zombie.hpp"

Zombie	*newZombie( std::string name ){
	return ( new Zombie( name )); // returning the created and named Zombie using the constructer
}
