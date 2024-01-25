#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void ){
	try{
		Bureaucrat B("b0", 15);
		// std::cout << B << std::endl;
		Form form("test_form", 1);
		std::cout << form;
		B.signForm(form);
		//---> it is not signed for some reason <---
		std::cout << form;
		// B.incrementGrade();
		// B.decrementGrade();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	// catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// catch (Bureaucrat::GradeTooHighException &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
}
