#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
	private:
		Brain*	brain;
	
	public:
		Cat( void );
		Cat( const Cat& f);
		Cat&  operator=( const Cat& f);
		~Cat();

		void	makeSound( void ) const;
		Brain*	getBrain() const;
};

#endif
