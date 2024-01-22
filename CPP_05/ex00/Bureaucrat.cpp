#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ){
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : name(name), grade(grade){
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : name(src.name), grade(src.grade){
} 

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ){
	if (this != &rhs)
		this->grade = rhs.grade;
	return *this;
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ){
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

std::string	  Bureaucrat::getName( void ) const{
	return (this->name);
}

int			  Bureaucrat::getGrade( void ) const{
	return (this->grade);
}

void		  Bureaucrat::incrementGrade( void ){
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--this->grade;
}

void		Bureaucrat::decrementGrade( void ){
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++this->grade;
}

Bureaucrat::~Bureaucrat( void ){
}