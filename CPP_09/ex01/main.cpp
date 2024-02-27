#include"RPN.hpp"

int	main( int ac, char *av[] ){
	(void)av;
	if (ac != 2){
		std::cerr << "\033[0;31mError: Invalid input\033[0m" << std::endl;
		std::cerr << "\033[0;32m\tUsage: ./RPN <nbr1> <nbr2> <operation>\033[0m" << std::endl;
		return (1);
	}
	RPN	  rpn;
	try{
		rpn.calculator(av[1]);
	}
	catch (std::exception& e){
		std::cerr << "\033[0;31mError: " << e.what() << "\033[0m" << std::endl;
	}
}
