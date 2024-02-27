#include "RPN.hpp"

//::::::::::::::::::constructors:::::::::::::::::::::::::
RPN::RPN( void ){
}

RPN::RPN( const RPN& src ){
	*this = src;
}

//::::::::::::::::::operators:::::::::::::::::::::::::
RPN& RPN::operator=( const RPN& rhs ){
	if (this != &rhs)
		this->rpnStack = rhs.rpnStack;
	return (*this);
}

//::::::::::::::::::methods:::::::::::::::::::::::::
void	RPN::calculator( const std::string& input ){
}


int	  RPN::toInt( const std::string& str ){
	int	n;

	std::stringstream	ss(str);
	ss >> n;
	// if (ss.fail())
	// 	throw();
	return (n);
}

//------------------Operations-------------------------
int	RPN::add( int a, int b ){
	return (a + b);
}

int	RPN::mult( int a, int b ){
	return (a * b);
}

int	RPN::sub( int a, int b ){
	return (a - b);
}

int	RPN::div( int a, int b ){
	// if (b == 0)
	// 	throw ();
	return (a / b);
}

int	RPN::pow( int a, int b ){
	return (pow(a, b));
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
RPN::~RPN( void ){
}
