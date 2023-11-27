#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	private:
	
	public:
		WrongCat( void );
		WrongCat( const WrongCat& f);
		WrongCat&  operator=( const WrongCat& f);
		~WrongCat();

		void	makeSound( void ) const;
};

#endif
