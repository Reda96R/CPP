#include "iter.hpp"

int	main( void ){
	std::cout << "\033[0;32m:::::::::::::::::::::int:::::::::::::::::::::\033[0m" << std::endl;
	int	test0[] = {0, 1, 2, 3};
	iter(test0, 4, printer);
	std::cout << std::endl;
	std::cout << "\033[0;32m:::::::::::::::::::::char:::::::::::::::::::::\033[0m" << std::endl;
	char	test1[] = {'a', 'b', 'c', 'd'};
	iter(test1, 4, printer);
	std::cout << std::endl;
	std::cout << "\033[0;32m:::::::::::::::::::::strings:::::::::::::::::::::\033[0m" << std::endl;
	std::string test2[4];
	test2[0] = "a0";
	test2[1] = "b1";
	test2[2] = "c2";
	test2[3] = "d3";
	iter(test2, 4, printer);
	std::cout << std::endl;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };
//
// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }
//
// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }
//
// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];
//
//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );
//
//   return 0;
// }
