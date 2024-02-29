#include "PmergeMe.hpp"

// template <typename T>
// void	check(const T &c)
// {
// 		typename T::const_iterator prev = c.begin();
//         typename T::const_iterator it = c.begin() + 1;
//         for (; it != c.end(); ++it) {
//                 if (*prev > *it) {
//                         std::cout << "\033[0;31mERROR\033[0m" << std::endl;
//                         return ;
//                 }
//         }
//         std::cout << "\033[0;32mSORTED\033[0m" << std::endl;
// }

int	main( int ac, char *av[] ){
	if (ac < 2){
		std::cerr << "\033[0;31mError: Invalid input\033[0m" << std::endl;
		std::cerr << "\033[0;32m\tUsage: ./PmergeMe \"<positive integer sequence>\"\033[0m" << std::endl;
		return (1);
	}
	try{
		PmergeMe<std::vector<int> > v(av + 1);
		std::cout << "\033[0;31mBefore	: \033[0m";
		v.printer();
		v.sorter(0, ac - 2);
		std::cout << "\033[0;32mAfter	: \033[0m";
		v.printer();
		std::cout << std::endl;
		v.infos();
		PmergeMe<std::deque<int> > d(av + 1);
		d.sorter(0, ac - 2);
		d.infos();
		// check(v);
		// check(d);
	}
	catch (std::exception& e){
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}
}
