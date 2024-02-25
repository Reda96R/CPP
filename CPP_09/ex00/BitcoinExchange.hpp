#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>


class BitcoinExchange{
	private:
		std::map<std::string, float>	dataBase;
	public:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& src );
		BitcoinExchange& operator=( const BitcoinExchange& rhs );
		~BitcoinExchange( void );


		std::string trim( const std::string& str );
		double		toDouble( const std::string& str );
		bool		allDigits(const std::string& str);
		bool		dateIsValid( const std::string& date );
		bool		priceIsValid( const std::string& price );
};

#endif // !BITCOINEXCHANGE_HPP
