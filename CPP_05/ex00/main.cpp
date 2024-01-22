#include "Bureaucrat.hpp"

int	main( void ){
	try{
		Bureaucrat B("b0", 1);
		B.decrementGrade();
		B.incrementGrade();
		std::cout << B << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}
