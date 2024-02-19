#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class Array{
	private:
		unsigned int	lengh;
		T*				array;
	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array& src);
		Array& operator=( const Array& rhs );
		const T& operator[]( unsigned int n ) const;
		T& operator[]( unsigned int n );
		~Array( void );

		unsigned int size( void ) const;

		class ArrayException : public std::exception{
			public:
				virtual const char* what() const throw(){
					return ("\033[0;31mInvalid Index!\033[0m");
				}
		};
};

#include "Array.tpp"
#endif
