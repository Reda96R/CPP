#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <algorithm>
# include <sstream>


class BitcoinExchange{
	private:
		std::map<std::string, std::string>	dataBase;
	public:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& src );
		BitcoinExchange& operator=( const BitcoinExchange& rhs );
		~BitcoinExchange( void );


		unsigned int	  toUnsigned( const std::string& str );
		double			  toDouble( const std::string& str );

		std::string		  trim( const std::string& str );
		void			  converter( std::string& date, std::string& price );

		bool			  allDigits(const std::string& str);
		bool			  dateIsValid( const std::string& date );
		bool			  priceIsValid( const std::string& price );
		bool			  leapYear( unsigned int day, unsigned int year );
};

#endif // !BITCOINEXCHANGE_HPP
