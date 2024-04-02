#include "RPN.hpp"

std::stack<int>	RPN::_nums;

RPN::RPN() {}

RPN::RPN( RPN const & other ) { (void)other; }

RPN& RPN::operator=( RPN const & other ) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

bool RPN::checkOperand( char c ) {
	if (c >= 48 && c <= 57)
		return true;
	return false;
}

int RPN::getNextNumber( void ) {
	int num = _nums.top();
	_nums.pop();
	return num;
}

void	RPN::addition( int first, int second ) { _nums.push(first + second); }
void	RPN::substact( int first, int second ) { _nums.push(first - second); }
void	RPN::multiply( int first, int second ) { _nums.push(first * second); }
void	RPN::division( int first, int second ) { _nums.push(first / second); }

void RPN::compute( std::string const & input ) {
	for (size_t i = 0; i < input.size(); i++) {
		if (input[i] == 32)
			continue;
		
		if (checkOperand(input[i])) {
			_nums.push(input[i] - '0');
			continue;
		}

		if (_nums.size() < 2)
			throw std::runtime_error("Error: not enough operands");

		int second = getNextNumber();
		int first = getNextNumber();
		switch (input[i]) {
			case '+':
				addition(first, second);
				break;
			case '-':
				substact(first, second);
				break;
			case '*':
				multiply(first, second);
				break;
			case '/':
				division(first, second);
				break;
			default:
				throw std::runtime_error("Error: unknown operator");
		}
	}

	if (_nums.size() == 1) {
		std::cout << _nums.top() << std::endl;
	}
	else {
		std::cerr << "Error: invalid number of operands left (" << _nums.size() << ") expected (1)" << std::endl;
	}
}
