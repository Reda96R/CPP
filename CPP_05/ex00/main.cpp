#include "includes/Bureaucrat.hpp"

int	main( void ){
	try{
		Bureaucrat B("b0", 2);
		B.incrementGrade();
		B.decrementGrade();
		std::cout << B << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
