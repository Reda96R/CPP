#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
		
		Fixed	operator+( const Fixed &f) const;
		Fixed	operator-( const Fixed &f) const;
		Fixed	operator*( const Fixed &f) const;
		Fixed	operator/( const Fixed &f) const;
		
		bool	operator>( const Fixed &f) const;
		bool	operator>=( const Fixed &f) const;
		bool	operator<( const Fixed &f) const;
		bool	operator<=( const Fixed &f) const;
		bool	operator==( const Fixed &f) const;
		bool	operator!=( const Fixed &f) const;

		/*:::::::::::prefix:::::::*/
		Fixed&	operator++( void );
		Fixed&	operator--( void );
		/*:::::::::::postfix::::::*/
		Fixed	operator++( int );
		Fixed	operator--( int );

		static Fixed&		max( Fixed& a, Fixed& b );
		static Fixed&		min( Fixed& a, Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<( std::ostream& o, Fixed const& n);

#endif
