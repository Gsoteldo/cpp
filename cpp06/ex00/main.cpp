#include <iostream>
#include "ScaleConverter.hpp"
// TODO: Ha realizar
//TODO: El programa debe aceptar solamente dos argumentos
//TODO: Debe interpretar que es originalmente
/*
	Es decir, detectar si lo que se recibe desde el principio es un 
	char, un int, un float o un double
	
	De ahí


*/
bool checkInput(int argc, char *argv[]) {

	(void)argv;
	if (argc != 2) {
		std::cerr << "Invalid number of argument, must be 2 argument";
		std::cerr << std::endl;
		return (false);
	}
	if (argv[1][0] == '\0') {
		std::cerr << "Empty argument is not allowed";
		std::cerr << std::endl;
		return (false);
	}

	// if ()


	return (true);
}

int main(int argc, char *argv[]) {

	// (void)argc;
	(void)argv;
	// char c = 127;
	if (!checkInput(argc, argv))
		return (1);

	std::string input = argv[1];
	ScaleConverter::convert(input);

	return (0);
}