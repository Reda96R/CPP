#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
	protected:
		std::string	  type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& f );
		Animal& operator=( const Animal& rhs);
		virtual ~Animal();

		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;
};

#endif
