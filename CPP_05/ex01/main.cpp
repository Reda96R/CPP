#include "includes/Bureaucrat.hpp"

int	main( void ){
	try{
		Bureaucrat B0("b0", 2);
		// B0.incrementGrade();
		std::cout << B0 << std::endl;
		Form F("f0", 1, 1);
		std::cout << F << std::endl;
		B0.signForm(F);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
