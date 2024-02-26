#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <sstream>
#include <string>

//::::::::::::::::::constructors:::::::::::::::::::::::::
//filling the internal dataBase
BitcoinExchange::BitcoinExchange( void ){
	size_t			delimiter;
	std::string		line;
	std::string		date;
	std::string		price;
    std::ifstream	input("data.csv", std::ifstream::in);

	if (!input.is_open()){
		std::cerr << "\033[0;31mError: Unable to open data base file!\033[0m" << std::endl;
		exit(0);
	}
	std::getline(input, line);
	while(std::getline(input, line)){
		delimiter = line.find('.');
		price = line.substr(delimiter + 1);
		this->dataBase[line.substr(0, delimiter)] = toDouble(price);
	}
	input.close();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& src ){
	*this = src;
}

//::::::::::::::::::operators:::::::::::::::::::::::::
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& rhs ){
	if (this != &rhs)
		this->dataBase = rhs.dataBase;
	return (*this);
}

//::::::::::::::::::methods:::::::::::::::::::::::::

//------------------helpers-------------------------
double	  BitcoinExchange::toDouble( const std::string& str ){
	double	n;

	std::stringstream	ss(str);
	ss >> n;
	return (n);
}

bool  BitcoinExchange::allDigits(const std::string& str) {
	for (unsigned int i = 0; i < str.length(); ++i)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}

std::string	  BitcoinExchange::trim( const std::string& str ){
	size_t	  start;
	size_t	  end;

	start = str.find_first_not_of(' ');
	if (std::string::npos == start)
		return (str);
	end = str.find_last_not_of(' ');
	return (str.substr(start, (end - start + 1)));
}

//------------------checkers-------------------------
bool	BitcoinExchange::dateIsValid( const std::string& date){
	if (date.empty() || date.length() != 10){
		std::cerr << "\033[0;31mError: Bad input => " << date << "\033[0m" << std::endl;
		return (false);
	}
	if (date[4] != '-' || date[7] != '-'){
		std::cerr << "\033[0;31mError: Bad input => " << date << "\033[0m" << std::endl;
		return (false);
	}
	
	std::string	  year = date.substr(0, 4);
	std::string	  month = date.substr(5, 2);
	std::string	  day = date.substr(8, 2);
	int			  nYear;
	int			  nMonth;
	int			  nDay;
	if (!allDigits(year) || !allDigits(month) || !allDigits(day)){
		std::cerr << "\033[0;31mError: Bad input => " << date << "\033[0m" << std::endl;
		return (false);
	}

    std::stringstream sYear(year);
    std::stringstream sMonth(month);
    std::stringstream sDay(day);

	sYear >> nYear;
	sMonth >> nMonth;
	sDay >> nDay;
	if (nYear > 2022 || nYear < 2009 ||
		nMonth > 12 || nMonth < 1 ||
		nDay > 31 || nDay < 1){
		std::cerr << "\033[0;31mError: Bad input => " << date << "\033[0m" << std::endl;
		return (false);
	}
	// if (nMonth == 2){
	//	if (nDay > 29)
	//	  return (false);
	// 	//To DO: check leap year
	// }
	if ((nMonth == 4 || nMonth == 6 || nMonth == 9 || nMonth == 11) &&
		 nDay > 30){
		std::cerr << "\033[0;31mError: Invalid date => " << date << "\033[0m" << std::endl;
		return (false);
	}

	return (true);
}

bool	BitcoinExchange::priceIsValid( const std::string& price ){
	if (price.empty() || price.find_first_not_of("0123456789.-+") != std::string::npos){
		std::cerr << "\033[0;31mError: Invalid price => " << price << "\033[0m" << std::endl;
		return (false);
	}
	if (price.at(0) == '-'){
		std::cerr << "\033[0;31mError: Not a positive number!\033[0m" << std::endl;
		return (false);
	}
	else if(price.at(0) == '+' && !std::isdigit(price.at(1))){
		std::cerr << "\033[0;31mError: Wrong number format => " << price << "\033[0m" << std::endl;
		return (false);
	}
	if (std::find(price.begin(), price.end(), '.') != price.end()){
		if (price.at(0) == '.' || ((std::count(price.begin(), price.end(), '.')) > 1)){
			std::cerr << "\033[0;31mError: Wrong number format => " << price << "\033[0m" << std::endl;
			return (false);
		}
	}
	if (price.length() > 10 || (price.length() == 10 && price > "2147483647")){
		std::cerr << "\033[0;31mError: Too large a number!\033[0m" << std::endl;
		return (false);
	}
	return (true);
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
BitcoinExchange::~BitcoinExchange( void ){
}
