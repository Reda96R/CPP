#include "Span.hpp"

#define NBRS 10000
int	main( void ){
	
//::::::::::::::::::First test::::::::::::::::::::::::::
	{
		try{
			Span  test(5);
			test.addNumber(0);
			test.addNumber(1);
			test.addNumber(2);
			test.addNumber(3);
			test.addNumber(4);
			//-----------------Full-----------------------
			// test.addNumber(5);
			
			std::cout << test.longestSpan() << std::endl;
			std::cout << test.shortestSpan() << std::endl;

			//----------------Empty-----------------------
			// Span  test1(0);
			// std::cout << test1.longestSpan() << std::endl;
			// std::cout << test1.shortestSpan() << std::endl;
		}
		catch(std::exception& e){
			std::cerr << "\033[0;31mError: " << e.what() << "\033[0m" << std::endl;
		}
	}

//::::::::::::::::::Second test:::::::::::::::::::::::::
	// {
	// 	std::vector<int> tmp1;
	// 	for (int i = 0; i < NBRS; i++)
	// 		tmp1.push_back(i * 9);
	// 	try{
	// 		Span  test(tmp1.size());
	// 		test.addRange(tmp1.begin(), tmp1.end());
	// 		std::cout << test.longestSpan() << std::endl;
	// 		std::cout << test.shortestSpan() << std::endl;
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << "\033[0;31mError: " << e.what() << "\033[0m" << std::endl;
	// 	}
	// }
}

//::::::::::::::::::Subject test::::::::::::::::::::::::
// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
