#include "Form.hpp"
#include "Bureaucrat.hpp"

// Form::Form( void ){
// }

Form::Form( const std::string& name, int getGradeToSign ) : name(name), gradeToSign(getGradeToSign), gradeToExecute(10){
	if (gradeToSign < 1)
		throw (Form::GradeTooHighException());
	if (gradeToSign > 150)
		throw (Form::GradeTooHighException());
}

Form::Form( const Form& src ) : name(src.getName()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()){
}

Form&	Form::operator=( const Form& rhs ){
	if ( this != &rhs )
		this->_signed = rhs.getSigned();
	return (*this);
}

std::ostream&	operator<<( std::ostream& o, const Form& rhs ){
	o << "\033[0;32m::: Form informations :::\033[0m" << std::endl;
	o << "\033[0;33mForm name:\033[0m\t" << rhs.getName() << std::endl;
	o << "\033[0;33mForm is signed:\033[0m\t" << rhs.getSigned() << std::endl;
	o << "\033[0;33mForm grade to sign:\033[0m\t" << rhs.getGradeToSign() << std::endl;
	o << "\033[0;33mForm grade to execute:\033[0m\t" << rhs.getGradeToExecute() << std::endl;
	return (o);
}

void	Form::beSigned( const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > gradeToSign)
		throw (Form::GradeTooLowException());
	this->_signed = true;
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

Form::~Form( void ){
}
