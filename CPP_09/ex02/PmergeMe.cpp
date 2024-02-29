#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

//::::::::::::::::::constructors:::::::::::::::::::::::::
template <typename T>
PmergeMe<T>::PmergeMe( void ){
}

template <typename T>
PmergeMe<T>::PmergeMe( char *input[] ){
	for (unsigned int i = 0; input[i]; ++i){
		if (!inputSanitizer(input[i])){
			throw (std::invalid_argument("Invalid arguments!"));
		}
		this->cont.push_back(toInt(input[i]));
	}
}

template <typename T>
PmergeMe<T>::PmergeMe( const PmergeMe& src ){
	*this = src;
}

//::::::::::::::::::operators:::::::::::::::::::::::::
template <typename T>
PmergeMe<T>&  PmergeMe<T>::operator=( const PmergeMe& rhs){
	if (this != &rhs){
		this->cont = rhs.cont;
		this->time = rhs.time;
	}
	return (*this);
}

//::::::::::::::::::Methods:::::::::::::::::::::::::
template <typename T>
int	PmergeMe<T>::divideAndConquer( int s, int e, std::vector<int>& medians ){
	
	std::sort(medians.begin(), medians.end(), comp(this->cont));
	int trueMedian = medians.at(medians.size() / 2);//Index of the true median in this->cont

	std::swap(this->cont[trueMedian], this->cont[e]);
	int	save = s;
	for (int i = s; i < e; ++i){
		if (cont[i] < cont[e]){
			std::swap(cont[i], cont[save]);
			save++;
		}
	}
	std::swap(cont[save], cont[e]);
	return (save);
}

template <typename T>
void	PmergeMe<T>::sorter( int s, int e ){
	std::clock_t	t0 = std::clock();

	//------------------------------Base cases---------------------------
	if (s == e) //One element
	{
		this->time = (double)(std::clock() - t0) / CLOCKS_PER_SEC;
		return ;
	}
	else if (e - s == 1) //Two elements
	{
		if (this->cont.at(0) > this->cont.at(1))
			std::swap(this->cont.at(0), this->cont.at(1));
		this->time = (double)(std::clock() - t0) / CLOCKS_PER_SEC;
		return ;
	}

	//----------------------------------finding the median------------------------------
	std::vector<int> medians;
	for (int i = s; i < e; i += 2){
		if (this->cont[i] > this->cont[i + 1])
			std::swap(cont[i], cont[i + 1]);
		medians.push_back(i + 1);
	}
	if (((e - s) + 1) % 2 != 0)
		medians.push_back(e);

	int	mid = divideAndConquer(s, e, medians);

	//----------------------------------repeting for smaller portions-----------------------------
	sorter(s, mid - 1);
	sorter(mid, e);
	this->time = (double)(std::clock() - t0) / CLOCKS_PER_SEC; 
}

//---------------------helpers------------------------
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

template <typename T>
std::string contName(const T& container) {
	std::string type = typeid(container).name();
	if (type.find("vector") != std::string::npos)
		return ("std::vector");
	return ("std::deque");
}

template <typename T>
void	PmergeMe<T>::printer( void ) const{
	for (unsigned int i = 0; i < this->cont.size(); ++i){
		std::cout << this->cont[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe<T>::infos( void ) const{
	std::cout
		<< "Time to process a range of " << this->cont.size()
		<< " elements with " << contName(this->cont)
		<< " : " << std::fixed << std::setprecision(5) << this->time << " us" << std::endl;
}


//::::::::::::::::::deconstructor:::::::::::::::::::::::::
template <typename T>
PmergeMe<T>::~PmergeMe( void ){
}

//explicit instantiation
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
