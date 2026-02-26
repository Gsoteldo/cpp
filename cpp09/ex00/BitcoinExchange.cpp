# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _exchangeRates() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj): _exchangeRates(obj._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this != &obj)
		_exchangeRates = obj._exchangeRates;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}