#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain{
	private:
		std::string	ideas[100];
	public:
		Brain( void );
		Brain( const Brain& f);
		Brain&	operator=(const Brain& rhs);
		~Brain( void );
};

#endif
