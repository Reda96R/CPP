#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain{
	public:
		std::string	ideas[100];
		Brain( void );
		Brain( const Brain& f);
		Brain&	operator=(const Brain& rhs);
		~Brain( void );
};

#endif
