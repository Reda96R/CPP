#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

//::::::::::::::::::constructors:::::::::::::::::::::::::
template <typename T>
Array<T>::Array( void ){
	this->array = new(T);
	this->lenght = 0;
}

template <typename T>
Array<T>::Array(unsigned int n){
	this->lenght = n;
	this->array = new(T[n]);
}

template <typename T>
Array<T>::Array( const Array& src ){
	this->array = new( T[src.lenght]);
	this->lenght = src.lenght;
	for (unsigned int i = 0; i < this->lenght; i++)
		this->array[i] = src.array[i];
}

//::::::::::::::::::operators:::::::::::::::::::::::::
template <typename  T>
Array<T>& Array<T>::operator=( const Array<T>& rhs){
	if (this != &rhs){
		delete[] this->array;
	this->array = new( T[rhs.lenght]);
	this->lenght = rhs.lenght;
	for (unsigned int i = 0; i < this->lenght; i++)
		this->array[i] = rhs.array[i];
	}
	return (*this);
}

template <typename T>
Array<T>& Array<T>::operator[]( unsigned int n) const{
	if (n >= this->lenght)
		throw(Array::ArrayException());
	return (this->array[n]);
}

//::::::::::::::::::methods:::::::::::::::::::::::::
template <typename T>
unsigned int Array<T>::size( void ) const{
	return (this->lenght);
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
template <typename T>
Array<T>::~Array( void ){
	delete[] this->array; //check the []
}

#endif
