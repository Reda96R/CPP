#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
#include <string>

class ScalarConverter{
	private:
		std::string	  input;
		char		  type;

	public:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& src);
		ScalarConverter& operator=( const ScalarConverter& rhs );
		~ScalarConverter( void );

		void	initData( std::string input );
		int		typeIdentifier( void );
		int		isChar( void );
		int		isInt( void );
		int		isFloat( void );
		int		isDouble( void );

		class ScalarConverterException : public std::exception{
			virtual const char* what() const throw(){
				return ("Invalide type");
			}
		};
};

std::ostream& operator<<( std::ostream& o, const ScalarConverter& rhs );

#endif
