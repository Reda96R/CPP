#include "includes/AForm.hpp"

AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	if (this->gradeToSign < 1 || gradeToExecute < 1)
		throw (AForm::GradeTooHighException());
	if (this->gradeToSign > 150 || gradeToExecute > 150)
		throw (AForm::GradeTooHighException());
	this->_signed = false;
}

AForm::AForm( const AForm& src ) : name(src.getName()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()), _signed(false){
}

AForm&	AForm::operator=( const AForm& rhs ){
	if ( this != &rhs )
		this->_signed = rhs.getSigned();
	return (*this);
}

std::ostream&	operator<<( std::ostream& o, const AForm& rhs ){
	o << "\033[0;32m::: AForm informations :::\033[0m" << std::endl;
	o << "\033[0;33mAForm name:\033[0m\t\t" << rhs.getName() << std::endl;
	o << "\033[0;33mAForm is signed:\033[0m\t\t" << rhs.getSigned() << std::endl;
	o << "\033[0;33mAForm grade to sign:\033[0m\t" << rhs.getGradeToSign() << std::endl;
	o << "\033[0;33mAForm grade to execute:\033[0m\t" << rhs.getGradeToExecute() << std::endl;
	return (o);
}

std::string AForm::getName( void ) const{
	return (this->name);
}

int		AForm::getGradeToSign( void ) const{
	return (this->gradeToSign);
}

int		AForm::getGradeToExecute( void ) const{
	return (this->gradeToExecute);
}

bool	AForm::getSigned( void ) const{
	return (this->_signed);
}

void	AForm::beSigned( const Bureaucrat& bureaucrat ){
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
}

AForm::~AForm( void ){
}
