#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int	main( void ){
	try{
		Bureaucrat B("b0", 2);
		Bureaucrat B1("b0", 150);
		B.incrementGrade();
		std::cout << B << std::endl;
		ShrubberyCreationForm S("s");
		RobotomyRequestForm R("R");
		PresidentialPardonForm P("p");
		B.signForm(S);
		B.executeForm(S);
		// B.signForm(R);
		// B.executeForm(R);
		// B.signForm(P);
		// B.executeForm(P);
		// std::cout << F << std::endl;
		// B.signForm(F);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
