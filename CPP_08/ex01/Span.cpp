#include "Span.hpp"

//::::::::::::::::::constructors:::::::::::::::::::::::::
Span::Span( void ){
}

Span::Span( unsigned int n){
	this->n = n;
}

Span::Span( const Span& src ){
	*this = src;
}

//::::::::::::::::::operators:::::::::::::::::::::::::
Span& Span::operator=( const Span& rhs ){
	if (this != &rhs){
		this->n = rhs.n;
		this->v = rhs.v;
	}
	return (*this);
}


//::::::::::::::::::methods:::::::::::::::::::::::::
void	Span::addNumber( unsigned int n ){
	if (this->v.size() > n )
		throw (std::out_of_range("\033[0;31mvector is full!\033[0m"));
	v.push_back( n );
}

int  Span::longestSpan( void ) const{
	if (this->v.size() < 2)
		throw (std::out_of_range("\033[0;31mvector is empty!\033[0m"));
	std::vector<int> tmp(v);
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

int	Span::shortestSpan( void ) const{
	if (this->v.size() < 2)
		throw (std::out_of_range("\033[0;31mvector is empty!\033[0m"));
	int	minSpan = Span::longestSpan();
	int span;
	std::vector<int> tmp(v);
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 1; i < tmp.size(); i++){
		span = tmp[i] - tmp[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
Span::~Span( void ){
}
