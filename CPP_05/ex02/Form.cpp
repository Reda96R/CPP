#include "includes/Form.hpp"

Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	if (this->gradeToSign < 1 || gradeToExecute < 1)
		throw (Form::GradeTooHighException());
	if (this->gradeToSign > 150 || gradeToExecute > 150)
		throw (Form::GradeTooHighException());
	this->_signed = false;
}

Form::Form( const Form& src ) : name(src.getName()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()), _signed(false){
}

Form&	Form::operator=( const Form& rhs ){
	if ( this != &rhs )
		this->_signed = rhs.getSigned();
	return (*this);
}

std::ostream&	operator<<( std::ostream& o, const Form& rhs ){
	o << "\033[0;32m::: Form informations :::\033[0m" << std::endl;
	o << "\033[0;33mForm name:\033[0m\t\t" << rhs.getName() << std::endl;
	o << "\033[0;33mForm is signed:\033[0m\t\t" << rhs.getSigned() << std::endl;
	o << "\033[0;33mForm grade to sign:\033[0m\t" << rhs.getGradeToSign() << std::endl;
	o << "\033[0;33mForm grade to execute:\033[0m\t" << rhs.getGradeToExecute() << std::endl;
	return (o);
}

std::string Form::getName( void ) const{
	return (this->name);
}

int		Form::getGradeToSign( void ) const{
	return (this->gradeToSign);
}

int		Form::getGradeToExecute( void ) const{
	return (this->gradeToExecute);
}

bool	Form::getSigned( void ) const{
	return (this->_signed);
}

void	Form::beSigned( const Bureaucrat& bureaucrat ){
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

Form::~Form( void ){
}
