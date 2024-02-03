#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "PresidentialPardonForm", 25, 5){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm( "PresidentialPardonForm", 25, 5), target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.target){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
	(void)rhs;
	return (*this);
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const{
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else if (!this->getSigned())
		throw (AForm::FormNotSignedException());
	std::cout << this->target << " \033[0;32mhas been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ){
}
