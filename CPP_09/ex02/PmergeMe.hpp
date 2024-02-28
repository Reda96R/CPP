#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>

template <typename T>
class PmergeMe {
	private:
		T	cont;

	public:
		PmergeMe( void );
		PmergeMe( const char *input[] );
		PmergeMe( const PmergeMe& src );
		PmergeMe &operator=( const PmergeMe& rhs );
		~PmergeMe( void );

		bool  inputSanitizer( const std::string& input );
		int	  toInt( const std::string& str );
		
};

#endif
