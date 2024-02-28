#include "PmergeMe.hpp"

int	main( int ac, char *av[] ){
	(void)av;
	if (ac != 2){
		std::cerr << "\033[0;31mError: Invalid input\033[0m" << std::endl;
		std::cerr << "\033[0;32m\tUsage: ./PmergeMe \"<positive integer sequence>\"\033[0m" << std::endl;
		return (1);
	}
	try{
		PmergeMe<std::vector<int> > v;
	}
	catch (std::exception& e){
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}
}
