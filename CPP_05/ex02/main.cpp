#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int	main( void ){
	try{
		// ===============================================
		Bureaucrat B("B", 2);
		Bureaucrat B1("B1", 150);
		std::cout << B << std::endl;
		std::cout << B1 << std::endl;
		std::cout << std::endl;

		// ===============================================
		PresidentialPardonForm P("P");
		std::cout << P << std::endl;
		RobotomyRequestForm R("R");
		std::cout << R << std::endl;
		ShrubberyCreationForm S("S");
		std::cout << S << std::endl;

		// ===============================================
		std::cout << ":::Unsigned forms:::" << std::endl;
		B.executeForm(P);
		B.executeForm(R);
		B.executeForm(S);
		std::cout << std::endl;

		// ===============================================
		B.signForm(P);
		B.signForm(R);
		B.signForm(S);
		std::cout << std::endl;

		// ===============================================
		std::cout << ":::Low grade:::" << std::endl;
		B1.executeForm(P);
		B1.executeForm(R);
		B1.executeForm(S);
		std::cout << std::endl;

		// ===============================================
		std::cout << ":::Form execution:::" << std::endl;
		B.executeForm(S);
		B.executeForm(R);
		B.executeForm(P);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
