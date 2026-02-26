#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <cstring>
# include <stdexcept>
# include <fstream>
# include <sstream>


class BitcoinExchange {
	private:
		std::map<std::string, float> _exchangeRates;

		bool validateDate(const std::string &date);

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
		void getInput(const std::string &input);
		void processData();
};

#endif