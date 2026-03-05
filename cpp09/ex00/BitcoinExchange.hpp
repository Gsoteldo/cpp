#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <cstring>
# include <cstdlib>
# include <stdexcept>
# include <fstream>
# include <sstream>


class BitcoinExchange {
	private:
		std::map<std::string, float> _exchangeRates;

		bool validateDate(const std::string &date);
		bool validateValue(const std::string &valueStr, float &value);

	public:

		class FileNotFoundException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class InvalidDateException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();


		void loadData(const std::string &filename);
		void ValidateInput(const std::string &input);
		void processData(const std::string &input);
		float getValueByDate(const std::string &date);

		void printMap();
};

#endif