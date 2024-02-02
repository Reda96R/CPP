#include "includes/PresidentialPardonForm.hpp"
#include "includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ){
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const{
	if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	std::cout << this->target << " \033[0;32mhas been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ){
}
