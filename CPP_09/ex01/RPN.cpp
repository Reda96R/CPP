#include "RPN.hpp"
#include <cctype>
#include <sstream>
#include <string>

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
const char*	  RPN::InvalidInputException::what() const throw(){
	return ("Invalid Input");
}

const char*	  RPN::DivisionByZeroException::what() const throw(){
	return ("Division by zero!");
}

const char*	  RPN::InsufficientOperandsException::what() const throw(){
	return ("Insufficient operands!");
}

//::::::::::::::::::methods:::::::::::::::::::::::::

bool  RPN::inputSanitizer( const std::string& input ){
	if (input.empty() || (input.find_first_not_of("0123456789+-/* ") != std::string::npos))
		return (false);
	return (true);
}

bool	RPN::numberChecker( const std::string& input ){
	unsigned int i = 0;
	if (input.length() == 0)
		return (false);
	if (input.at(0) == '+' || input.at(0) == '-'){
		if (input.length() == 1)
			return (false);
		i = 1;
	}
	while (i < input.length())
		if (!std::isdigit(input[i++]))
			return (false);
	return (true);
}

int	RPN::selecter( const std::string& input ){
	std::string			ops[] = {"+", "-", "*", "/"};
	for (unsigned int i = 0; i < 4; i++)
	    if (input == ops[i])
			return (i);
	return (-1);
}

bool  RPN::allDigits(const std::string& str) {
	for (unsigned int i = 0; i < str.length(); ++i)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}

void	RPN::calculator( const std::string& input ){
	if (!inputSanitizer(input))
		throw (RPN::InvalidInputException());

	std::stringstream	ss(input);
	std::string			s;
	int					r;
	int					l;

	while (ss >> s){
		int	  i = selecter(s);
		if (i >= 0){
			if (this->rpnStack.size() < 2)
				throw (RPN::InsufficientOperandsException());
			l = this->rpnStack.top();
			this->rpnStack.pop();
			r = this->rpnStack.top();
			this->rpnStack.pop();
			//TODO: push the operation result
		}
		else{
			if (numberChecker(s))
				this->rpnStack.push(toInt(s));
			else
				throw (RPN::InvalidInputException());
		}
		// if (this->rpnStack != 1)
			//TODO: too many operands exception
		// std::cout << this->rpnStack.top() << std::endl;
	}
}

int	  RPN::toInt( const std::string& str ){
	int	n;

	std::stringstream	ss(str);
	ss >> n;
	if (ss.fail())
		throw(RPN::InvalidInputException());
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

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
RPN::~RPN( void ){
}
