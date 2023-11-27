#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string	  type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& f );
		Animal& operator=( const Animal& rhs);
		~Animal();

		std::string	  getType( void ) const;
};

#endif
