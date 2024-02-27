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
		int		selecter( const std::string& input );
		int		toInt( const std::string& str );
		
		int		add( int a, int b );
		int		mult( int a, int b );
		int		sub( int a, int b );
		int		div( int a, int b );

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
};

#endif
