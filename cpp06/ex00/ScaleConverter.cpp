#include "ScaleConverter.hpp"

ScaleConverter::ScaleConverter() {
	std::cout << "ScaleConverter created" << std::endl;
}

ScaleConverter::ScaleConverter(const ScaleConverter &obj) {
	if (this != &obj) {
		std::cout << "ScaleConverter copied" << std::endl;
	}	
}


ScaleConverter &ScaleConverter::operator=(const ScaleConverter &obj) {
	if (this != &obj) {
		std::cout << "ScaleConverted assigned" << std::endl;
	}	
	return *this;
}

ScaleConverter::~ScaleConverter() {
	std::cout << "ScaleConverter destroyed" << std::endl;
}


bool ScaleConverter::isPseudoLiteral(std::string input) {
	if (input.compare("nanf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0) {
		return (true); // float
	} else if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0) {
		return (true); // double
	}
	return (false); // not a pseudo literal
}

int ScaleConverter::detectType(const std::string &input) {
	
	char c;
	bool hasSign = false;
	bool hasDecimal = false;
	bool hasFloat = false;
	int countDigits = 0;

	if (input.length() == 1 && !isdigit(input[0]) && IS_PRINTABLE(input[0])) {
		return 0; // char
	}

	if (isPseudoLiteral(input)) {
		return 4; // pseudo literal
	}

	for (std::size_t i = 0; i < input.length(); i++) {

		// std::cout << "Current char: " << input[i] << std::endl;
		c = input[i];
		if (c == '+' || c == '-') {
			if (hasSign) {
				return -1; // unknown
			}
			hasSign = true;
		}

		if (c == '.') {
			if (hasDecimal) {
				return -1; // unknown
			}
			hasDecimal = true;
		}

		if (c == 'f' && i == input.length() - 1) {
			std::cout << "Current chaaaar: " << input[i] << std::endl;
			hasFloat = true;
		}
		
		if (isdigit(c)) {
			countDigits++;
		}
	}
	if (countDigits == 0) {
		return -1; // unknown
	}

	if (hasFloat) {
		return 2; // float
	}

	if (hasDecimal) {
		return 3; // double
	}

	return 1; // int
}

void ScaleConverter::printChar(const std::string &input, int type) {

	char c = 0;
	char *endptr;
	long num = 0;
	if (type == 4) {
		std::cout << "char: impossible" << std::endl;
		return;
	} else if (type == 0) {
		c = input[0];
	} else if (type == 1) {
		num = strtol(input.c_str(), &endptr, 10);

		if (*endptr != '\0' || num < 0 || num > 127) {
			std::cout << "char: impossible" << std::endl;
			return;
		}
		c = static_cast<char>(num);
	}

	if (!IS_PRINTABLE(c)) {
		std::cout << "char: Non printable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

void ScaleConverter::printInt(const std::string &input, int type) {

	char *endptr;

	long num = static_cast<int>(strtol(input.c_str(), &endptr, 10));

	   if (input.length() >= 11 || *endptr != '\0' || INT_OUT_OF_RANGE(num) || type == 4) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
	std::cout << "int: "  << num << std::endl;
}

void ScaleConverter::printFloat(const std::string &input, int type) {

	char *endptr;

	if (type == 4) {
		if (input == "nanf" || input == "+inff" || input == "-inff") {
			std::cout << "float: " << input << std::endl;
		} else {
			std::cout << "float: " << input << "f" << std::endl;
		}
		return;
	}

	float num = static_cast<float>(strtof(input.c_str(), &endptr));

	if (*endptr != '\0' || FLOAT_OUT_OF_RANGE(num)) {
		std::cout << "float: impossible" << std::endl;
		return;
	}

	std::cout << "float: " << num << "f" << std::endl;
}

void ScaleConverter::printDouble(const std::string &input, int type) {

	char *endptr;

	if (type == 4) {

			std::cout << "double: " << input << std::endl;
		return;
	}

	double num = static_cast<double>(strtod(input.c_str(), &endptr));

	if (*endptr != '\0' || DOUBLE_OUT_OF_RANGE(num)) {
		std::cout << "double: impossible" << std::endl;
		return;
	}

	std::cout << "double: " << num << std::endl;
}

void ScaleConverter::printAll(const std::string &input, int type) {

	printChar(input, type);
	printInt(input, type);
	printFloat(input, type);
	printDouble(input, type);
}


void ScaleConverter::convert(const std::string &input) {
	// Implementation of conversion logic goes here
	int type = detectType(input);

	if (type == -1) {

		std::cout << "Error: Invalid input" << std::endl;
		return ;
	}
	printAll(input, type);

	// switch (type)
	// {
	// case 0:
	// 	std::cout << "Detected type: char" << std::endl;
	// 	break;
	// case 1:
	// 	std::cout << "Detected type: int" << std::endl;
	// 	break;
	// case 2:
	// 	std::cout << "Detected type: float" << std::endl;
	// 	break;
	// case 3:
	// 	std::cout << "Detected type: double" << std::endl;
	// 	break;
	// default:
	// 	std::cout << "Detected type: unknown" << std::endl;
	// 	break;
	// }
}
