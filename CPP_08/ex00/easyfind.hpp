#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>

template < typename T >
int	easyfind( T& cont, int n ){
	typename T::iterator iter = std::find (cont.begin(), cont.end(), n);
	if (iter == cont.end())
		throw (std::exception());
	return (*iter);
}

#endif // !EASYFIND_HPP
