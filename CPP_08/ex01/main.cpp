#include "Span.hpp"

int	main( void ){
	Span  test(4);
	test.addNumber(1);
	test.addNumber(4);
	test.addNumber(5);
	test.addNumber(9);
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
}
