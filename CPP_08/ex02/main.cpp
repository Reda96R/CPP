#include "MutantStack.hpp"
#include <list>
#include <vector>

int	main( void ){
	std::cout << "\033[0;32m::::::::::::::::::MutantStack::::::::::::::::::\033[0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(0);
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	std::cout << "Stack size: " << mstack.size() << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\033[0;32m::::::::::::::::::::Vector:::::::::::::::::::::\033[0m" << std::endl;
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	std::cout << "Vector size: " << v.size() << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\033[0;32m:::::::::::::::::::::List::::::::::::::::::::::\033[0m" << std::endl;
	std::list<int> l;
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	std::cout << "List size: " << l.size() << std::endl;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}


// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }
