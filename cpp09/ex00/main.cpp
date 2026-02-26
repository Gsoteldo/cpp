#include "BitcoinExchange.hpp"




bool checkerArguments(int argc, char **argv) {
	(void)argv;
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

	try
	{
		BitcoinExchange btc;

		btc.validateDate(static_cast<std::string>("2026-02-30"));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}