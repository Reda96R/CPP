#ifndef RPN_HPP
# define RPN_HPP

#include <exception>
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
		bool	inputSanitizer( const std::string& input );
		bool	numberChecker( const std::string& input );
		bool	allDigits(const std::string& str);
		int		selector( const std::string& input );
		int		toInt( const std::string& str );
		
		int		add( int l, int r );
		int		mul( int l, int r );
		int		sub( int l, int r );
		int		div( int l, int r );

		class InvalidInputException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class DivisionByZeroException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		
		class InsufficientOperandsException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		
		class TooManyOperandsException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#endif
