#include "RPN.hpp"

//::::::::::::::::::constructors:::::::::::::::::::::::::
RPN::RPN( void ){
}

RPN::RPN( const RPN& src ){
	*this = src;
}

//::::::::::::::::::operators:::::::::::::::::::::::::
RPN& RPN::operator=( const RPN& rhs ){
	// if (this != &rhs)
	return (*this);
}

//::::::::::::::::::methods:::::::::::::::::::::::::
void	RPN::calculator( std::string input ){

}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
RPN::~RPN( void ){
}
