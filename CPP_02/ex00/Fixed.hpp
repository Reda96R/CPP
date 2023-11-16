#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		static const int  fracional = 8;
		int	  value;
	public:
		Fixed();
		Fixed& operator=( const Fixed &oldO );
		//add a copy constructer
		~Fixed();
		
		void	setRawBits (int const raw );
		int		getRawBits( void ) const;
};

#endif
