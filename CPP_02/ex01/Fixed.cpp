#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int n) : value(n << fracional){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : value(roundf(n * (1 << fracional))){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &oldO){
	std::cout << "Copy constructer called" << std::endl;
	*this = oldO;
}

Fixed& Fixed::operator=(const Fixed &oldO){
	std::cout << "Copy assignment operator called" << std::endl;
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
	return (static_cast<float>(this->getRawBits()) / (1 << fracional)); // static_cast
}

int	  Fixed::toInt() const{
	return (this->value >> fracional);
}

Fixed::~Fixed(){
	std::cout << "Destructer called" << std::endl;
}
