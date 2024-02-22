#include "easyfind.hpp"

int	main( void ){
	std::cout << "\033[0;33m:::::::::::::::::Vector:::::::::::::::::::::::\033[0m" << std::endl;
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	try{
		std::cout << easyfind(v, 3) << std::endl;
		// std::cout << easyfind(v, 4) << std::endl;
	}
	catch ( std::exception& e ){
		std::cerr << "\033[0;31mError: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[0;33m:::::::::::::::::List:::::::::::::::::::::::::\033[0m" << std::endl;
	std::list<int> l;
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	try{
		std::cout << easyfind(l, 3) << std::endl;
		// std::cout << easyfind(v, 4) << std::endl;
	}
	catch ( std::exception& e ){
		std::cerr << "\033[0;31mError: " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[0;33m:::::::::::::::::Deque::::::::::::::::::::::::\033[0m" << std::endl;
	std::deque<int> d;
	d.push_back(0);
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	try{
		std::cout << easyfind(d, 3) << std::endl;
		// std::cout << easyfind(v, 4) << std::endl;
	}
	catch ( std::exception& e ){
		std::cerr << "\033[0;31mError: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;
}
