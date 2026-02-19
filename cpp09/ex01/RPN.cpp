#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &obj) {
	_stack = obj._stack;
}
RPN &RPN::operator=(const RPN &obj) {
	if (this != &obj)
		_stack = obj._stack;

	return (*this);
}
RPN::~RPN() {}


bool isNumber(const std::string &tok) {
	size_t i = 0;
	
	if (tok.empty())
		return (false);
	if (tok[0] == '-' || tok[0] == '+')
		i++;
	for (; i < tok.size(); i++) {
		if (!isdigit(tok[i]))
			return (false);
	}
	return (true);
}

bool isOperator(const std::string &tok) {
	if (tok.size() == 1 && IS_OP(tok[0]))
		return (true);
	return (false);
}


void RPN::printStack() const {
	std::stack<int> stackCopy = _stack;

	while (!stackCopy.empty()) {
		std::cout << stackCopy.top() << std::endl;
		stackCopy.pop();
	}
}

int calculate(int leftNumber, std::string op, int rightNumber) {
	
	const char *operatorType = op.c_str(); 

	switch (operatorType[0])
	{
		case '+':
			return (leftNumber + rightNumber);
		case '-':
			return (leftNumber - rightNumber);
		case '*':
			return (leftNumber * rightNumber);
		case '/':
			if (rightNumber == 0)
				throw std::runtime_error("Division by zero.");
			return (leftNumber / rightNumber);
		default:
			throw std::runtime_error("Invalid operator.");
	}
}

void RPN::operate(char **argv) {

	std::istringstream iss(argv[1]);
	std::string tok;

	int leftNumber;
	int rightNumber;
	std::string op;

	while (iss >> tok) {
		if (isNumber(tok))
			_stack.push(atoi(tok.c_str()));
		else if (isOperator(tok)) {
			op = tok;
			rightNumber = _stack.top();
			_stack.pop();
			leftNumber = _stack.top();
			_stack.pop();
			
			_stack.push(calculate(leftNumber, op,rightNumber));
		}

		// if (this->_stack.size() != 1)
		// 	throw std::runtime_error("The user input has too many operands.");
	}

	printStack();


}