#include "BitcoinExchange.hpp"

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
		exit(1);
	}
	std::getline(input, line);
	while(std::getline(input, line)){
		delimiter = line.find(',');
		price = line.substr(delimiter + 1);
		this->dataBase[line.substr(0, delimiter)] = price;
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
//------------------Converter-------------------------
void	BitcoinExchange::converter( std::string& date, std::string& price ){
	std::map<std::string, std::string>::iterator it = dataBase.find(date);
	if (it != dataBase.end()){
		std::cout << date << " => " << price << " = " << toDouble(price) * toDouble(it->second) << std::endl;
	}
	else if (it == dataBase.end()){
		double	  rate = toDouble((--dataBase.lower_bound(date))->second);
		std::cout << date << " => " << price << " = " << toDouble(price) * rate << std::endl;
	}
}

//------------------Helpers-------------------------
double	  BitcoinExchange::toDouble( const std::string& str ){
	double	n;

	std::stringstream	ss(str);
	ss >> n;//TODO: check if the conversion was successfull
	return (n);
}

unsigned int	  BitcoinExchange::toUnsigned( const std::string& str ){
	unsigned int	n;

	std::stringstream	ss(str);
	ss >> n;//TODO: check if the conversion was successfull
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

bool	BitcoinExchange::leapYear( unsigned int day, unsigned int year ){
	if ( day == 29 && (!(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
		return (false);
	}
	return (true);
}

//------------------Validators-------------------------
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
	if (!allDigits(year) || !allDigits(month) || !allDigits(day)){
		std::cerr << "\033[0;31mError: Bad input => " << date << "\033[0m" << std::endl;
		return (false);
	}

	unsigned int			  nYear = toUnsigned(year);
	unsigned int			  nMonth = toUnsigned(month);
	unsigned int			  nDay = toUnsigned(day);
	if (nYear > 2022 || nYear < 2009 ||
		nMonth > 12 || nMonth < 1 ||
		nDay > 31 || nDay < 1){
		std::cerr << "\033[0;31mError: Bad input => " << date << "\033[0m" << std::endl;
		return (false);
	}
	if (nMonth == 2){
		if (nDay > 29 || !leapYear(nDay, nYear)){
			std::cerr << "\033[0;31mError: Invalid date => " << date << "\033[0m" << std::endl;
			return (false);
		}
	}
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
	if (std::find(price.begin(), price.end(), '-') != price.end()){
		if (price.at(0) == '-'){
			std::cerr << "\033[0;31mError: Not a positive number!\033[0m" << std::endl;
			return (false);
		}
		else if (std::find(std::find(price.begin(), price.end(), '-'), price.end(), '-') != price.end()){
			std::cerr << "\033[0;31mError: Wrong number format => " << price << "\033[0m" << std::endl;
			return (false);
		}
	}
	if (std::find(price.begin(), price.end(), '+') != price.end()){
		if ( price.at(0) != '+' || (std::count(price.begin(), price.end(), '+') > 1)){
			std::cerr << "\033[0;31mError: Wrong number format => " << price << "\033[0m" << std::endl;
			return (false);
		}
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
	if (toDouble(price) > 1000.0){
		std::cerr << "\033[0;31mError: Too large a number!\033[0m" << std::endl;
		return (false);
	}
	return (true);
}

//::::::::::::::::::deconstructor:::::::::::::::::::::::::
BitcoinExchange::~BitcoinExchange( void ){
}
