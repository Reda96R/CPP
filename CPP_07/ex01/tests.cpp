#include "iter.hpp"

// template < typename T >
void  ft_there(const int& n){
	(void)n;
	std::cout << "success" << std::endl;
}

// template < typename T >
void	ft_here(int& x, void (*f)(const int& n)){
	f(x);
}





template < typename T >
void	printer(const T& o ){
	std::cout << o << std::endl;
}

template < typename T >
void	ft_test( T* o, void (*f)( T&)){
	// (void)o;
	// int	test1[] = {0, 1, 2, 3};
	for (size_t i = 0; i < 4; i++)
		f(o[i]);
		// f(test1[i]);
}
int	main( void ){

	int n = 10;
	ft_here(n, ft_there);
	// int	test0[] = {0, 1, 2, 3};
	// ft_test(test0, printer);
	// iter(test0, 4, printer<const int>); // doesn't work
	// int	test0[] = {0, 1, 2, 3};
	// iter(test0, 4, printer <const int>); 
	



	// std::cout << "\033[0;32m:::::::::::::::::::::int:::::::::::::::::::::\033[0m" << std::endl;
	// int	test0[] = {0, 1, 2, 3};
	// iter(test0, 4, printer<int>);
	// std::cout << std::endl;
	// std::cout << "\033[0;32m:::::::::::::::::::::char:::::::::::::::::::::\033[0m" << std::endl;
	// char	test1[] = {'a', 'b', 'c', 'd'};
	// iter(test1, 4, printer<char>);
	// std::cout << std::endl;
	// std::cout << "\033[0;32m:::::::::::::::::::::strings:::::::::::::::::::::\033[0m" << std::endl;
	// std::string test2[4];
	// test2[0] = "a0";
	// test2[1] = "b1";
	// test2[2] = "c2";
	// test2[3] = "d3";
	// iter(test2, 4, printer<std::string>);
	// std::cout << std::endl;
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
//   iter( tab, 5, print<const int>);
//   iter( tab2, 5, print<Awesome> );
//
//   return 0;
// }
