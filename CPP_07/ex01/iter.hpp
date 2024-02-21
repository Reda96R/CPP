#ifndef ITER_HPP
# define ITER_HPP

# include<iostream>

template < typename T >
void	printer(const T& o ){
	std::cout << o << std::endl;
}

template < typename T, typename U>
void	iter( T* array, size_t lenght, void (*f)( U&) ){
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}

#endif
