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

	return (true);
}


bool BitcoinExchange::validateValue(const std::string &valueStr, float &value) {
//TODO:  Comprobar con numeros extra que no son numericos
	char	*endptr;
	for (size_t i = 0; i < valueStr.length(); i++) {
		if ((!isdigit(valueStr[i]) and valueStr[i] not_eq 'e' ) and valueStr[i] != '.') {
			std::cerr << "Error: Invalid value format. Expected a numeric value." << std::endl;
			return (false);
		}
	}

	value = strtof(valueStr.c_str(), &endptr);

	if (endptr == valueStr.c_str()) {
		std::cerr << "Error: Invalid value format. Expected a numeric value." << std::endl;
		return (false);
	}
	if (value < 0) {
		std::cerr << "Error: Value cannot be negative." << std::endl;
		return (false);
	}
	if (value > 1000) {
		std::cerr << "Error: Value cannot be greater than 1000." << std::endl;
		return (false);
	}
	return (true);
}


//Debugging para mostrar que se han cargado los datos correctamente. Se puede eliminar despues
void BitcoinExchange::printMap() {
	for (std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
		std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
	}
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

		std::getline(ss, date, ',');
		ss >> value;

		if (not validateDate(date))
			throw InvalidDateException();
		_exchangeRates[date] = value;
	}

	// printMap();

	file.close();
}

float BitcoinExchange::getValueByDate(const std::string &date) {
	std::map<std::string, float>::iterator it;

	it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end() or it->first != date) {
		if (it == _exchangeRates.begin())
			throw InvalidDateException();
		--it;
	}
	return (it->second);
}

void BitcoinExchange::ValidateInput(const std::string &input) {

	std::ifstream file(input.c_str());
	std::string line;

	if (not file)
		throw FileNotFoundException();

	std::getline(file, line); // Skip header

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		float value;
		size_t separator = line.find(" | ");
		std::string valueStr;

		if (separator != std::string::npos) {
			date = line.substr(0, separator);
			valueStr = line.substr(separator + 3);
		}

		std::istringstream(valueStr) >> value;

		if (separator not_eq std::string::npos) {
			date = line.substr(0, separator);
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (not validateDate(date)) {

			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (not validateValue(valueStr, value)) {
			continue;
		}

		float rate = getValueByDate(date);
		std::cout << date << " => " << value
				<< " = " << value * rate << std::endl;
	}

	file.close();
}

void BitcoinExchange::processData(const std::string &input) {
	this->loadData("data.csv");
	this->ValidateInput(input);
	
}