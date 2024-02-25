#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <string>

int	main( int ac, char *av[] ){
	(void)av;
	if (ac != 2){
		std::cerr << "\033[0;31mError: Invalid input\033[0m" << std::endl;
		std::cerr << "\033[0;32m\tUsage: ./btc <Input.txt>\033[0m" << std::endl;
		return (1);
	}
	BitcoinExchange	  btc;
	std::string		  line;
    std::ifstream	  input(av[1], std::ifstream::in);

	if (!input.is_open()){
		std::cerr << "\033[0;31mError: Unable to open provided file!\033[0m" << std::endl;
		return (1);
	}
	if (input.peek() == std::ifstream::traits_type::eof()){
		std::cerr << "\033[0;31mError: Empty file!\033[0m" << std::endl;
		return (1);
	}
	std::getline(input, line);
	if (line != "date | value"){
		std::cerr << "\033[0;31mError: Invalid file format!\033[0m" << std::endl;
		return (1);
	}
	while (std::getline(input, line)){
		size_t	delimiter = line.find('|');
		if (delimiter == std::string::npos || line.length() < delimiter + 2){
			std::cerr << "\033[0;31mError: bad input => " << line << "\033[0m" << std::endl;
			continue ;
		}
		std::string	  price = btc.trim(line.substr(delimiter + 1));
		std::string	  date = btc.trim(line.substr(0, delimiter));
		if (!btc.dateIsValid(date) || !btc.priceIsValid(price)){
			continue ;
		}
	}
}
