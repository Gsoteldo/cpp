#include "PmergeMe.hpp"



bool checkArguments(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Error: No arguments provided." << std::endl;
		return false;
	}
	for (int i = 1; i < argc; ++i) {
		// if (!isNumber(argv[i])) {
		// 	std::cerr << "Error: Invalid argument '" << argv[i] << "'." << std::endl;
		// 	return false;
		// }
	}
	return true;
}

int main(int argc, char *argv[]) {
	if (!checkArguments(argc, argv)) {
		return (1);
	}
	return (0);
}