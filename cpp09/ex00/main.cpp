#include "BitcoinExchange.hpp"




bool checkerArguments(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: Argument must be 2" << std::endl
				<< "RNC <expression>" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char *argv[]) {
	if (!checkerArguments(argc, argv))
		return (1);

	return (0);
}