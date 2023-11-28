#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	private:
		Brain*	brain;

	public:
		Dog( void );
		Dog( const Dog& f);
		Dog&  operator=( const Dog& f);
		~Dog();

		void	makeSound( void ) const;
		Brain*	getBrain() const;
};

#endif 
