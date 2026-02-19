#include "RPN.hpp"

// bool isNumber(const std::string &tok) {
// 	size_t i = 0;
	
// 	if (tok.empty())
// 		return (false);
// 	if (tok[0] == '-' || tok[0] == '+')
// 		i++;
// 	for (; i < tok.size(); i++) {
// 		if (!isdigit(tok[i]))
// 			return (false);
// 	}
// 	return (true);
// }

// bool isOperator(const std::string &tok) {
// 	if (tok.size() == 1 && IS_OP(tok[0]))
// 		return (true);
// 	return (false);
// }

bool checkerArguments(int argc, char **argv) {
	
	
	if (argc < 2) {
		std::cerr << "Error: Argument must be 2" << std::endl
				<< "RNC <expression>" << std::endl;
		return (false);
	}

	std::istringstream iss(argv[1]);
	std::string tok;

	while (iss >> tok) {

		if (!isNumber(tok) && !isOperator(tok)) {
			std::cerr << "it's not a number or a operator" << std::endl;
			return (false);
		}
	}

	return (true);
} 

int main(int argc, char *argv[]) {

	

	if (!checkerArguments(argc, argv))
		return (1);

	RPN rpn = RPN();
	
	rpn.operate(argv);
	

	return (0);
}