#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <typeinfo>
# include <sstream>
# include <vector>
# include <deque>
# include <cstdio> // for exit()

template <typename T>
class PmergeMe {
	private:
		T		  cont;
		double	  time;

		struct comp{
			const T& tmp;
			comp( const T& cont ) : tmp(cont) {} 
			bool  operator()(int l, int r){
				return (this->tmp[l] < this->tmp[r]);
			}
		};

	public:
		PmergeMe( void );
		PmergeMe( char *input[] );
		PmergeMe( const PmergeMe& src );
		PmergeMe &operator=( const PmergeMe& rhs );
		~PmergeMe( void );

		void		  sorter( int s, int e );
		int			  divideAndConquer( int s, int e, std::vector<int>& medians );
		void		  infos( void ) const;
		void		  printer( void ) const;
		bool		  inputSanitizer( const std::string& input );
		int			  toInt( const std::string& str );


		// typename T::const_iterator begin() const {
		// 	return cont.begin();
		// }
		// typename T::const_iterator end() const {
		// 	return cont.end();
		// }
		// typedef typename T::const_iterator const_iterator;
};

#endif
