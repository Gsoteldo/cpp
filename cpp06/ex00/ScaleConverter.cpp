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


int ScaleConverter::detectType(const std::string &input) {
	// Implementation of type detection logic goes here
	if (input.length() == 1 && !isdigit(input[0]) && IS_PRINTABLE(input[0])) {
		return 0; // char
	}

	if (input.compare("nanf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0) {
		return 2; // float
	}
	if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0) {
		return 3; // double
	}






	if (input[0] == '-' || input[0] == '+' ) {
		if (input.length() > 1 && isdigit(input[1])) {
			return 1; // int
		}
	} else if (isdigit(input[0])) {
		return 1; // int
	}
	
	return -1; // unknown
}




void ScaleConverter::convert(const std::string &input) {
	// Implementation of conversion logic goes here
	int type = detectType(input);

	switch (type)
	{
	case 0:
		std::cout << "Detected type: char" << std::endl;
		break;
	case 1:
		std::cout << "Detected type: int" << std::endl;
		break;
	case 2:
		std::cout << "Detected type: float" << std::endl;
		break;
	case 3:
		std::cout << "Detected type: double" << std::endl;
		break;
	default:
		std::cout << "Detected type: unknown" << std::endl;
		break;
	}
}
