#include "RPN.hpp"
#include <cstddef>

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

const char*	  RPN::TooManyOperandsException::what() const throw(){
	return ("Too many operands!");
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
		if (input.length() == 1 || input.at(0) == '-')
			return (false);
		i = 1;
	}
	while (i < input.length())
		if (!std::isdigit(input[i++]))
			return (false);
	if (toInt(input) >= 10)
		return (false);
	return (true);
}

int	RPN::selector( const std::string& input ){
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
	int					l;
	int					r;

	while (ss >> s){
		int	  i = selector(s);
		if (i >= 0){
			if (this->rpnStack.size() < 2)
				throw (RPN::InsufficientOperandsException());
			r = this->rpnStack.top();
			this->rpnStack.pop();
			l = this->rpnStack.top();
			this->rpnStack.pop();
			switch(i){
				case 0 : this->rpnStack.push(add(l, r)); break ;
				case 1 : this->rpnStack.push(sub(l, r)); break ;
				case 2 : this->rpnStack.push(mul(l, r)); break ;
				case 3 : this->rpnStack.push(div(l, r)); break ;
			}
		}
		else{
			if (numberChecker(s))
				this->rpnStack.push(toInt(s));
			else
				throw (RPN::InvalidInputException());
		}
	}
	if (this->rpnStack.size() != 1)
		throw (RPN::TooManyOperandsException());
	std::cout << this->rpnStack.top() << std::endl;
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
int	RPN::add( int l, int r ){
	return (l + r);
}

int	RPN::mul( int l, int r ){
	return (l * r);
}

int	RPN::sub( int l, int r ){
	return (l - r);
}

int	RPN::div( int l, int r ){
	if (r == 0)
		throw (RPN::DivisionByZeroException());
	return (l / r);
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
RPN::~RPN( void ){
}
