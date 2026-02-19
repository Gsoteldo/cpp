#ifndef RPN_HPP
# define RPN_HPP
# define IS_OP(c) (c == '+' || c == '-' || c == '*' || c == '/')

# include <iostream>
# include <sstream>
# include <string>
# include <stack>
# include<cstdlib>

class RPN {
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
		~RPN();

		void operate(char **argv);
		void printStack() const;
};

bool isNumber(const std::string &tok);
bool isOperator(const std::string &tok);


#endif