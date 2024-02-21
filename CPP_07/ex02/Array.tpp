#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

//::::::::::::::::::constructors:::::::::::::::::::::::::
template <typename T>
Array<T>::Array( void ){
	this->array = new(T);
	this->lengh = 0;
}

template <typename T>
Array<T>::Array(unsigned int n){
	this->lengh = n;
	this->array = new T[n];
}

template <typename T>
Array<T>::Array( const Array& src ){
	this->array = new T[src.lengh];
	this->lengh = src.lengh;
	for (unsigned int i = 0; i < this->lengh; i++)
		this->array[i] = src.array[i];
}

//::::::::::::::::::operators:::::::::::::::::::::::::
template <typename  T>
Array<T>& Array<T>::operator=( const Array<T>& rhs){
	if (this != &rhs){
		delete[] this->array;
		this->array = new T[rhs.lengh];
		this->lengh = rhs.lengh;
		for (unsigned int i = 0; i < this->lengh; i++)
			this->array[i] = rhs.array[i];
	}
	return (*this);
}

template <typename T>
const T& Array<T>::operator[]( unsigned int n) const{
	if (n >= this->lengh)
		throw(Array::ArrayException());
	return (array[n]);
}

template <typename T>
T& Array<T>::operator[]( unsigned int n){
	if (n >= this->lengh)
		throw(Array::ArrayException());
	return (array[n]);
}

//::::::::::::::::::methods:::::::::::::::::::::::::
template <typename T>
unsigned int Array<T>::size( void ) const{
	return (this->lengh);
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
template <typename T>
Array<T>::~Array( void ){
	delete[] this->array;
}

#endif
