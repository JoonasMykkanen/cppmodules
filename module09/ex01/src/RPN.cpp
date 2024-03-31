#include "RPN.hpp"

std::stack<char>	RPN::_operators;
std::stack<int>		RPN::_operands;
int					RPN::_result = 0;

RPN::RPN() {}

RPN::RPN( RPN const & other ) {
	(void)other;
}

RPN& RPN::operator=( RPN const & other ) {
	if (this != &other) {

	}
	return *this;
}

RPN::~RPN() {}

bool RPN::checkOperator( char c ) {
	switch (c) {
		case '+':
			return true;
		case '-':
			return true;
		case '/':
			return true;
		case '*':
			return true;
		default:
			return false;
	}
}

bool RPN::checkOperand( char c ) {
	if (c >= 48 && c <= 57)
		return true;
	return false;
}

void RPN::processInput( std::string const & input ) {
	for (int_least32_t i = input.size() - 1; i >= 0; i--) {
		std::cout << "index: " << i << " arg: " <<input[i] << std::endl;
		if (input[i] == 32) {
			continue;
		}
		else if (checkOperator(input[i])) {
			_operators.push(input[i]);
			continue;
		}
		else if (checkOperand(input[i])) {
			_operands.push(input[i] - '0');
			continue;
		}
		else {
			throw std::out_of_range("Error: invalid argument found");
		}
	}
}

char RPN::getNextOperator( void ) {
	char ret = _operators.top();
	_operators.pop();
	return ret;
}

int	RPN::getNextOperand( void ) {
	int ret = _operands.top();
	_operands.pop();
	return ret;
}

void RPN::doMathStuff( void ) {
	if (_operands.size() == 1 && _operators.size() == 0) {
		_result = _operands.top();
		return;
	}
	else if (_operators.size() < 1 || _operands.size() < 2) {
		throw std::runtime_error("Error: invalid amount of arguments");
	}

	int second = getNextOperand();
	int first = getNextOperand();
	char op = getNextOperator();

	switch (op) {
		case '+':
			_operands.push(first + second);
			break;
		case '-':
			_operands.push(first - second);
			break;
		case '/':
			_operands.push(first / second);
			break;
		case '*':
			_operands.push(first * second);
			break;
		default:
			throw std::runtime_error("Error!");
	}

	doMathStuff();
}

void RPN::compute( std::string const & input ) {
	try {
		processInput(input);
		doMathStuff();
		std::cout << _result << std::endl;
	}
	catch (std::exception& error) { std::cerr << error.what() << std::endl; }
}
