#include "includes/ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm( void ){
// }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target){
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	(void)rhs;
	return (*this);
}
void	ShrubberyCreationForm::execute( const Bureaucrat& executor )const{
	std::ofstream outfile((this->target + "_shrubbery").c_str());

	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else if (!this->getSigned())
		throw (AForm::FormNotSignedException());
	if (!outfile)
	{
		std::cerr << "\033[0;31m" << this->target + "_shrubbery " << "is not reachable!\033[0m" << std::endl;
		return ;
	}
	outfile << 
	"\n"
	"               ,@@@@@@@,\n"
	"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
	"    ,&%%&%&&%,@@@@@/@@@@@@,888888/8o\n"
	"  ,%&\%&&%&&%,@@@@@@@/@@@88888888/88'\n"
	"   %&&%&%&/%&&%@@@@@/ /@@@88888888888'\n"
	"   %&&%/ %&%%&&@@@ V /@@' `8888 `/88'\n"
	"   `&%% ` /%&'    |.|        | '|8'\n"
	"       |o|        | |         | |\n"
	"       |.|        | |         | |\n"
	"jgs \\/ ._-//_/__/  ,__//__\\/.  _//__/_\n"
	"        .      ~,\n"
	"    .       .   |\\   .    ' '-.\n"
	"    ___________/  \\____________\n"
	"   /  Why is it that sometimes \\\n"
	"  |	  the road to simplicity    |\n"
	"  |	    seems so complex?	    |\n"
	"   \\___________________________/\n"
	<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){
}
