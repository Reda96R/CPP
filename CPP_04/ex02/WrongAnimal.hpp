#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string	  type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( const WrongAnimal& f );
		WrongAnimal& operator=( const WrongAnimal& rhs);
		~WrongAnimal();

		void		  makeSound( void ) const;
		std::string	  getType( void ) const;
};

#endif 
