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

/*:::::::::::::::Arithmetic operators::::::::::::::::::::*/
Fixed	Fixed::operator+(const Fixed& f) const {
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& f) const {
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& f) const {
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& f) const {
	return (Fixed(this->toFloat() / f.toFloat()));
}

/*:::::::::::::::Comparison operators::::::::::::::::::::*/
bool	Fixed::operator>(const Fixed& f) const {
	return (this->getRawBits() > f.getRawBits());
}

bool	Fixed::operator<(const Fixed& f) const {
	return (this->getRawBits() < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed& f) const {
	return (!(this->getRawBits() < f.getRawBits()));
}

bool	Fixed::operator<=(const Fixed& f) const {
	return (!(this->getRawBits() > f.getRawBits()));
}

bool	Fixed::operator==(const Fixed& f) const {
	return (this->getRawBits() == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed& f) const {
	return (!(this->getRawBits() == f.getRawBits()));
}

/*:::::::::::::::Increment/Decrement operators:::::::::::*/
Fixed&	  Fixed::operator++(){
	++this->value;
	return (*this);
} 

Fixed&	  Fixed::operator--(){
	--this->value;
	return (*this);
} 

Fixed	  Fixed::operator++(int){
	Fixed f = (*this);
	operator++(); // invoking the pre-increment operator
	return (f);
} 

Fixed	  Fixed::operator--(int){
	Fixed f(*this);
	operator--();
	return (f);
} 

/*:::::::::::::::Max & Min::::::::::::::::::::::::::::::*/
Fixed&	  Fixed::max(Fixed& a, Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed&	  Fixed::min(Fixed& a, Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed::~Fixed(){
}
