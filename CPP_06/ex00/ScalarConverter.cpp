#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter( void ){
	this->type = 0;
}

ScalarConverter::ScalarConverter( const ScalarConverter& src ){
	*this = src;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& rhs ){
	if (this != &rhs){
	}
	return (*this);
}

void	ScalarConverter::initData( std::string input ){
	this->input = input;
	if (!(this->typeIdentifier())){
		throw ScalarConverter::ScalarConverterException();
	}
}

//::::::::::::::::::::::::::::Type identifying:::::::::::::::::::::::::::::::::

int	ScalarConverter::typeIdentifier( void ){
	if (ScalarConverter::isChar())
		type = 'c';
	else if (ScalarConverter::isInt())
		type = 'i';
	else if (ScalarConverter::isFloat())
		type = 'f';
	else if (ScalarConverter::isDouble())
		type = 'd';
	return (type);
}

int	ScalarConverter::isChar( void ){
	return (this->input.length() == 1 && std::isprint(input[0]) && std::isalpha(input[1]));
}

int	ScalarConverter::isInt( void ){
	int	i;

	i = 0;
	if ( input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length())
		if (!(std::isdigit(input[i])))
			return (0);
	return (1);
}

int	ScalarConverter::isFloat( void ){
}

ScalarConverter::~ScalarConverter( void ){
}
