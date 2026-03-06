#include "PmergeMe.hpp"

bool isNumber(const char *str) {
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool checkArguments(int argc, char *argv[]) {
	if (argc <= 2) {
		std::cerr << "Error: No enough arguments provided." << std::endl;
		return false;
	}
	for (int i = 1; i < argc; ++i) {
		if (!isNumber(argv[i])) {
			std::cerr << "Error: Invalid argument '" << argv[i] << "'." << std::endl;
			return (false);
		}
		int tmp = std::strtol(argv[i], NULL, 10);
		if (tmp < 0) {
			std::cerr << "Error: Negative number '" << argv[i] << "' is not allowed." << std::endl;
			return (false);
		} else if (tmp > INT_MAX) {
			std::cerr << "Error: Number '" << argv[i] << "' exceeds the maximum allowed value." << std::endl;
			return (false);
		}
	}


	return (true);
}

int main(int argc, char *argv[]) {
	if (!checkArguments(argc, argv))
		return (1);

	PmergeMe pmergeMe(argv, argc);
	 std::cout << "Before: " ;
	 pmergeMe.printVector(std::vector<int>());

	pmergeMe.run();
	return (0);
}