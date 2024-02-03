#include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target){
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
	(void)rhs;
	return (*this);
}

void	RobotomyRequestForm::execute( const Bureaucrat& executor )const{
	float	randomValue;
	
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else if (!this->getSigned())
		throw (AForm::FormNotSignedException());
	std::srand(time(0));
	randomValue = (float)(std::rand()) / RAND_MAX;
	if (randomValue <= 0.5){
		std::cout << "\033[0;33mVrrrrrrrrr... Zzzzzz... Clank, clank, clank!\033[0m" << std::endl;
		std::cout << "\033[0;32m" << this->target << " has been robotomized successfully!\033[0m" << std::endl;
	}
	else
		std::cout << "\033[0;31m" << this->target << " failed the robotomizing!\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ){
}
