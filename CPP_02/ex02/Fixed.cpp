#include "Fixed.hpp"

Fixed::Fixed(){
	this->value = 0;
}

Fixed::Fixed(const int n) : value(n << fracional){
}

Fixed::Fixed(const float n) : value(roundf(n * (1 << fracional))){
}

Fixed::Fixed(const Fixed &oldO){
	*this = oldO;
}

Fixed& Fixed::operator=(const Fixed &oldO){
	if (this != &oldO)
		this->value = oldO.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, Fixed const& f){
	out << f.toFloat();
	return (out);
}

int	Fixed::getRawBits( void ) const{
	return (this->value);
}

void	Fixed::setRawBits(int const raw){
	this->value = raw;
}

float	Fixed::toFloat() const{
	return ((float)this->getRawBits()) / (1 << fracional);
}

int	  Fixed::toInt() const{
	return (this->value >> fracional);
}

Fixed::~Fixed(){
}
