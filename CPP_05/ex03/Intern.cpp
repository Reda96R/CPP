# include "includes/Intern.hpp"

Intern::Intern( void ){
}

Intern::Intern( const Intern& src ){
	*this = src;
}

Intern& Intern::operator=( const Intern& rhs ){
	(void) rhs;
	return (*this);
}

AForm* createPresidentialPardonForm( std::string target ){
	return (new PresidentialPardonForm(target));
}

AForm* createRobotomyRequestForm( std::string target ){
	return (new RobotomyRequestForm(target));
}

AForm*	creatShrubberyCreationForm( std::string target ){
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm( std::string name, std::string target ){
	std::string	  forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (*formPtr[3])(std::string target) = {
		&createPresidentialPardonForm,
		&createRobotomyRequestForm,
		&creatShrubberyCreationForm
	};

	for(int i = 0; i < 3; i++){
		if (name == forms[i]){
			std::cout << "\033[0;32mIntern creates\033[0m " << name << std::endl;
			return (formPtr[i](target));
		}
	}
	std::cout << "\033[0;31mIntern couldn't create\033[0m " << name << std::endl;
	return (NULL);
}

Intern::~Intern( void ){
}
