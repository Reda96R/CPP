#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private:
		std::string name;

	public:
		Zombie();
		Zombie	*newZombie(std::string name);
		void	initName(std::string name);
		void	announce();
		~Zombie();
};

Zombie	  *zombieHorde( int N, std::string name );

#endif
