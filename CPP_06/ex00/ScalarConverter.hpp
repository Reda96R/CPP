#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter{
	private:

	public:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& src);
		ScalarConverter& operator=( const ScalarConverter& rhs );
		~ScalarConverter( void );
};

std::ostream& operator<<( std::ostream& o, const ScalarConverter& rhs );

#endif
