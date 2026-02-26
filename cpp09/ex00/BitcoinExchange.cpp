# include "BitcoinExchange.hpp"

//Exception handling
const char* BitcoinExchange::FileNotFoundException::what() const throw() {
	return ("Error: File not found");
}

const char* BitcoinExchange::InvalidDateException::what() const throw() {
	return ("Error: Invalid date format. Expected format in data.csv: YYYY-MM-DD ");
}

BitcoinExchange::BitcoinExchange(): _exchangeRates() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj): _exchangeRates(obj._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this != &obj)
		_exchangeRates = obj._exchangeRates;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


bool BitcoinExchange::validateDate(const std::string &date) {
	struct tm tm;


	memset(&tm, 0,sizeof(struct tm));

	if (not strptime(date.c_str(), "%Y-%m-%d", &tm))
		return (false);
	if (date.size() not_eq 10)
		return (false);

	int day = tm.tm_mday;
	int month = tm.tm_mon;
	int year = tm.tm_year;

	if (mktime(&tm) == -1 || tm.tm_year not_eq year || tm.tm_mon not_eq month || tm.tm_mday not_eq day)
		return (false);

	// std::cout << "Date is valid: " << (tm.tm_year > 0) << std::endl;
	// std::cout << "Parsed date: " << (tm.tm_year + 1900) << "-" << (tm.tm_mon ) << "-" << tm.tm_mday << std::endl;

	return (true);

}


// Los datos se del archivo .csv se guardan en el mapa para que se puedan revisar despues.
// De este archivo depende el resto del programa

//TODO: Añadir excepcion si alguno de las fechas está mal
//* Importante: Solo en el que se basa. En el el input debe mostrar un mensaje de error en el propio terminal
void BitcoinExchange::loadData(const std::string &filename) {

	std::ifstream file(filename.c_str());
	std::string line;

	if (not file)
		throw FileNotFoundException();

	std::getline(file, line); // Skip header

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		float value;

		ss >> date >> value;

		if (!validateDate(date))
			throw InvalidDateException();

		_exchangeRates[date] = value;
	}

}

void BitcoinExchange::getInput(const std::string &input) {
	(void)input;
}

void BitcoinExchange::processData() {}