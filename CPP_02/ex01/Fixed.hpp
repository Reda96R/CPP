#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		static const int  fracional = 8;
		int	  value;
	public:
		Fixed();
		Fixed	( const int n);
		Fixed	( const float n);
		Fixed	( const Fixed &oldO );
		Fixed&	operator=( const Fixed &oldO );
		~Fixed	();
		
		void	setRawBits (int const raw );
		int		getRawBits( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<( std::ostream& o, Fixed const& n);

#endif
