#include "PmergeMe.hpp"
#include <stdexcept>

//::::::::::::::::::constructors:::::::::::::::::::::::::
template <typename T>
PmergeMe<T>::PmergeMe( void ){
}

template <typename T>
PmergeMe<T>::PmergeMe( const char *input[] ){
	for (unsigned int i = 0; input[i]; ++i){
		if (!inputSanitizer(input[i])){
			throw (std::invalid_argument("Invalid arguments!"));
		}
		this->cont.push_back(toInt(input[i]));
	}
}

template <typename T>
PmergeMe<T>::PmergeMe( const PmergeMe& src ){
	(void)src;
}

//::::::::::::::::::operators:::::::::::::::::::::::::
template <typename T>
PmergeMe<T>&  PmergeMe<T>::operator=( const PmergeMe& rhs){
	(void)rhs;
}



//::::::::::::::::::methods:::::::::::::::::::::::::
template <typename T>
bool  PmergeMe<T>::inputSanitizer( const std::string& input ){
	if (input.empty() || (input.find_first_not_of("0123456789") != std::string::npos))
		return (false);
	return (true);
}

template <typename T>
int	  PmergeMe<T>::toInt( const std::string& str ){
	int	n;

	std::stringstream	ss(str);
	ss >> n;
	if (ss.fail())
		throw(std::invalid_argument("Invalid arguments!"));
	return (n);
}



//::::::::::::::::::deconstructor:::::::::::::::::::::::::
template <typename T>
PmergeMe<T>::~PmergeMe( void ){
}
