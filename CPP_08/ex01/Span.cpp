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
void	Span::addNumber( unsigned int nbr ){
	if (this->v.size() >= this->n )
		throw (std::out_of_range("vector is full!"));
	v.push_back( nbr );
}

void	Span::addRange( std::vector<int>::const_iterator s, std::vector<int>::const_iterator e ){
	if (this->v.size() >= this->n )
		throw (std::out_of_range("vector is full!"));
	this->v.insert( this->v.end(), s, e);
}

unsigned int  Span::longestSpan( void ) const{
	if (this->v.size() < 2)
		throw (std::out_of_range("amount of numbers is not enough!"));
	std::vector<int> tmp(v);
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

unsigned int	Span::shortestSpan( void ) const{
	if (this->v.size() < 2)
		throw (std::out_of_range("amount of numbers is not enough!"));
	unsigned int	minSpan = Span::longestSpan();
	for (size_t i = 1; i < v.size(); ++i){
		unsigned int span = std::abs(v[i] - v[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
Span::~Span( void ){
}
