#include "includes/Bureaucrat.hpp"

int	main( void ){
	try{
		Bureaucrat B("b0", 2);
		B.incrementGrade();
		B.decrementGrade();
		std::cout << B << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
}
