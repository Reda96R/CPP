#include "includes/Bureaucrat.hpp"

int	main( void ){
	try{
		Bureaucrat B0("B0", 0);
		Bureaucrat B1("B1", 151);
		// Bureaucrat B0("B0", 1);
		// Bureaucrat B1("B1", 150);
		// B0.incrementGrade();
		// B1.decrementGrade();
		std::cout << B1 << std::endl;
		std::cout << B0 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
