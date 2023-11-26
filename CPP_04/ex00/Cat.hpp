#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
	private:
	
	public:
		Cat();
		Cat( const Cat& f);
		Cat&  operator=( const Cat& f);
		~Cat();

		void	makeSound( void ) const;
};

#endif
