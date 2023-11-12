#include "MyReplace.hpp"

int	main(int ac, char *av[]){
	if (ac == 4){
		MyReplace rep(av[1]);
		rep.Replacer(av[2], av[3]);
	}
	else {
		std::cerr << "\033[0;31mError: Incorrect number of parameters" << std::endl;
		std::cerr << "\033[0;32m    Usage: ./myreplace <filename> <target> <replacement>\033[0m" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (0);
}
