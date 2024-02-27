#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <sstream>

class RPN{
	private:
		std::stack<int> rpnStack;
	public:
		RPN( void );
		RPN( const RPN& src );
		RPN& operator=( const RPN& rhs );
		~RPN( void );

		void	calculator( const std::string& input );
		int		toInt( const std::string& str );
		
		int		add( int a, int b );
		int		mult( int a, int b );
		int		sub( int a, int b );
		int		div( int a, int b );
		int		pow( int a, int b );
};

#endif
