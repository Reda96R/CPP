#include "iter.hpp"

int	main( void ){
	std::cout << ":::::::::::::::::::::int:::::::::::::::::::::" << std::endl;
	int	test0[] = {0, 1, 2, 3};
	iter(test0, 4, printer);
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::char[]:::::::::::::::::::::" << std::endl;
	char	test1[] = {'a', 'b', 'c', 'd'};
	iter(test1, 4, printer);
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::char[][]:::::::::::::::::::::" << std::endl;
	std::string test2[4];
	test2[0] = "a0";
	test2[1] = "b1";
	test2[2] = "c2";
	test2[3] = "d3";
	iter(test2, 4, printer);
	std::cout << std::endl;
}
