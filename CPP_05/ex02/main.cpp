#include "includes/Bureaucrat.hpp"

int	main( void ){
	try{
		Bureaucrat B("b0", 2);
		B.incrementGrade();
		std::cout << B << std::endl;
		Form F("f0", 1, 1);
		std::cout << F << std::endl;
		B.signForm(F);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
