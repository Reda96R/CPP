#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static int i = 0;

Base*	generate( void ){

	std::srand((std::time(0)));
	i += std::rand();
	if (!(i % 5) && !(i % 3))
		return (new A);
	else if ((i % 5) && (i % 3))
		return (new B);
	else
		return (new C);
	i += std::rand();
}

void	identify( Base* p ){
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "\033[0;31mUnkown type\033[0m" << std::endl;
}

void	identify( Base& p ){
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception& e){
	}
	try{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception& e){
	}
	try{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception& e){
		std::cout << "\033[0;31mUnkown type\033[0m" << std::endl;
	}
}

int	main( void ){

	std::cout << "\033[2;37m::::::::::::::::::::::::::::::::\033[0m" << std::endl;
	Base* Base = generate();
	std :: cout << "Base ptr : ";
	identify(Base);
	std :: cout << "Base ref : ";
	identify(*Base);
	delete (Base);
	std::cout << std::endl;

	std::cout << "\033[2;37m::::::::::::::::::::::::::::::::\033[0m" << std::endl;
	A* a = new(A);
	B* b = new(B);
	C* c = new(C);

	std :: cout << "A ptr : ";
	identify(a);
	std :: cout << "A ref : ";
	identify(*a);
	delete (a);
	std::cout << std::endl;

	std :: cout << "B ptr : ";
	identify(b);
	std :: cout << "B ref : ";
	identify(*b);
	delete (b);
	std::cout << std::endl;

	std :: cout << "C ptr : ";
	identify(c);
	std :: cout << "C ref : ";
	identify(*c);
	delete (c);
}
