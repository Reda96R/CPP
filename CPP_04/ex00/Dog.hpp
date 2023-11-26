#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	private:

	public:
		Dog();
		Dog( const Dog& f);
		Dog&  operator=( const Dog& f);
		~Dog();

		void	makeSound( void ) const;
};

#endif 
