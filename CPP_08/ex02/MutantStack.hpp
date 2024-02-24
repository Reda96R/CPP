#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template < typename T >
class MutantStack : public std::stack<T>{
	public:
		MutantStack( void ){
		};
		MutantStack( const MutantStack& src){
			*this = src;
		}
		MutantStack& operator=( const MutantStack& rhs ){
			(void)rhs;
			return (*this);
		}
		virtual ~MutantStack( void ){
		};

		typedef	typename std::deque<T>::iterator iterator;

		iterator	begin( void ){
			return ( this->c.begin() );
		}
		iterator	end( void ){
			return ( this->c.end());
		}
};

#endif
