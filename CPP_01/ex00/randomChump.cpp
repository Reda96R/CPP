#include "Zombie.hpp"

void randomChump( std::string name ){
	Zombie	  infected( name );
	infected.announce();
}
