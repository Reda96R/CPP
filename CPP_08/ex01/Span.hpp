#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span{
	private:
		std::vector<int>	  v;
		unsigned int		  n;

	public:
		Span( void );
		Span( unsigned int n );
		Span( const Span& src );
		Span& operator=( const Span& rhs );
		~Span( void );

		void	addNumber( unsigned int n );
		void	addRange( std::vector<int>::const_iterator s, std::vector<int>::const_iterator e );
		int		longestSpan( void ) const;
		int		shortestSpan( void ) const;
};

#endif
