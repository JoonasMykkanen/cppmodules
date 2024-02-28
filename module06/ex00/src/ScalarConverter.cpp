/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:30:36 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/28 21:09:54 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

char	ScalarConverter::_charValue = 0;
int		ScalarConverter::_charStatus = 1;

double	ScalarConverter::_dblValue = 0;
int		ScalarConverter::_dblStatus = 1;

float	ScalarConverter::_fltValue = 0;
int		ScalarConverter::_fltStatus = 1;

int		ScalarConverter::_intValue = 0;
int		ScalarConverter::_intStatus = 1;

int		ScalarConverter::_type = NoneType;
bool	ScalarConverter::_negative = false;
bool	ScalarConverter::_printing = true;


ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( ScalarConverter const & other ) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const & other ) {
	( void ) other;
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}

void	ScalarConverter::chooseType( std::string const & input ) {
	if (input.empty()) {
		_type = ErrorType;
	}
	else if (!input.compare("-inff") || !input.compare("+inff")) {
		if (input[0] == '-')
			_negative = true;
		_type = FltType;
		_charStatus = _IMPOSSIBLE;
		_intStatus = _IMPOSSIBLE;
		_fltStatus = _INF;
		_dblStatus = _INF;
	}
	else if (!input.compare("-inf") || !input.compare("+inf")) {
		if (input[0] == '-')
			_negative = true;
		_type = DblType;
		_charStatus = _IMPOSSIBLE;
		_intStatus = _IMPOSSIBLE;
		_fltStatus = _INF;
		_dblStatus = _INF;
	}
	else if (!input.compare("nan") || !input.compare("nanf")) {
		if (input.back() == 'f')
			_type = FltType;
		else
			_type = DblType;
		_charStatus = _IMPOSSIBLE;
		_intStatus = _IMPOSSIBLE;
		_fltStatus = _NAN;
		_dblStatus = _NAN;
	}
	else if ((input.find('.') != std::string::npos && input.back() == 'f')
	&& input.find_first_not_of(".f01234567898") == std::string::npos) {
		_type = FltType;
		_charStatus = _POSSIBLE;
		_intStatus = _POSSIBLE;
		_fltStatus = _POSSIBLE;
		_dblStatus = _POSSIBLE;
	}
	else if (input.find('.') != std::string::npos
	&& input.find_first_not_of(".01234567898") == std::string::npos) {
		_type = DblType;
		_charStatus = _POSSIBLE;
		_intStatus = _POSSIBLE;
		_fltStatus = _POSSIBLE;
		_dblStatus = _POSSIBLE;
	}
	else if (input.find_first_not_of("0123456789") == std::string::npos) {
		for (size_t i = 0; i < input.size(); i++) {
			char c = input[i];
			
			if (i == 0 && c == '-') {
				_negative = true;
				continue;
			}
			
			if (!isdigit(c))
			{
				_type = ErrorType;
				return;
			}
		}
		_type = IntType;
		_charStatus = _POSSIBLE;
		_intStatus = _POSSIBLE;
		_fltStatus = _POSSIBLE;
		_dblStatus = _POSSIBLE;
	}
	else if (input.size() == 1 && std::isprint(input[0])) {
		_type = CharType;

		_charStatus = _POSSIBLE;
		_intStatus = _POSSIBLE;
		_fltStatus = _POSSIBLE;
		_dblStatus = _POSSIBLE;
	}
	else
		_type = ErrorType;
}

void	ScalarConverter::convertInt( std::string const & input ) {
	try {
		_intValue = std::stoi(input);

		if (_charStatus)
			_charValue = static_cast<char>(_intValue);
		if (_fltStatus)
			_fltValue = static_cast<float>(_intValue);
		if (_dblStatus)
			_dblValue = static_cast<double>(_intValue);
	}
	catch (std::exception &e)
	{
		_intStatus = _IMPOSSIBLE;
	}
}

void	ScalarConverter::convertChar( std::string const & input ) {
	try {
		_charValue = input[0];

		if (_intStatus)
			_intValue = static_cast<int>(_charValue);
		if (_fltStatus)
			_fltValue = static_cast<float>(_charValue);
		if (_dblStatus)
			_dblValue = static_cast<double>(_charValue);
	}
	catch (std::exception &e) {
		_charStatus = _IMPOSSIBLE;
	}
}

void	ScalarConverter::convertFloat( std::string const & input ) {
	try {
		if (_fltStatus == _INF) {
			if (_negative)
				_fltValue = -std::numeric_limits<float>::infinity();
			else
				_fltValue = std::numeric_limits<float>::infinity();
		}
		else if (_fltStatus == _NAN)
			_fltValue = std::numeric_limits<float>::quiet_NaN();
		else {
			_fltValue = std::stod(input);
		}

		if (_intStatus)
			_intValue = static_cast<int>(_fltValue);
		if (_dblStatus)
			_dblValue = static_cast<double>(_fltValue);
		if (_charStatus)
			_charValue = static_cast<char>(_fltValue);
	}
	catch (std::exception &e) {
		_fltStatus = _IMPOSSIBLE;
	}
}

void	ScalarConverter::convertDouble( std::string const & input ) {
	try {
		if (_dblStatus == _INF) {
			if (_negative)
				_dblStatus = -std::numeric_limits<double>::infinity();
			else
				_dblValue = std::numeric_limits<double>::infinity();
		}
		else if (_dblStatus == _NAN)
			_dblValue = std::numeric_limits<double>::quiet_NaN();
		else {
			_dblValue = std::stod(input);
		}

		if (_intStatus)
			_intValue = static_cast<int>(_dblValue);
		if (_charStatus)
			_charValue = static_cast<char>(_dblValue);
		if (_fltStatus)
			_fltValue = static_cast<float>(_dblValue);
	}
	catch (std::exception &e) {
		_dblStatus = _IMPOSSIBLE;
	}
}

void ScalarConverter::performCasting( std::string const & input ) {
	switch (_type) {
		case CharType:
			convertChar(input);
			break;

		case IntType:
			convertInt(input);
			break;

		case FltType:
			convertFloat(input);
			break;
		
		case DblType:
			convertDouble(input);
			break;
		
		default:
			std::cout << "Error with input: " << input << std::endl;
			_printing = false;
			break;
	}
}

void	ScalarConverter::checkLimits( std::string const & input ) {
	try {
		long double bigNumber = std::stold(input);

		if (bigNumber < std::numeric_limits<int>::min() || bigNumber > std::numeric_limits<int>::max()) {
			_intStatus = _IMPOSSIBLE;
			if (_type == IntType)
				_printing = false;
		}
		if (bigNumber < std::numeric_limits<float>::lowest() || bigNumber > std::numeric_limits<float>::max()) {
			if (_fltStatus != _INF && _fltStatus != _NAN) {
				_fltStatus = _IMPOSSIBLE;
				if (_type == FltType)
					_printing = false;
			}
		}
		if (bigNumber < std::numeric_limits<double>::lowest() || bigNumber > std::numeric_limits<double>::max()) {
			if (_fltStatus != _INF && _fltStatus != _NAN) {
				_dblStatus = _IMPOSSIBLE;
				if (_type == DblType)
					_printing = false;
			}
		}
		if (bigNumber < 0 || bigNumber > 127)
			_charStatus = _IMPOSSIBLE;
		
		std::string types[] = {"char", "int", "float", "double"};
		if (!_printing)
			std::cout << "Could not convert to <" << types[_type] << ">" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cerr << "Could not check limits: " << e.what() << std::endl;
	}
}

void ScalarConverter::printOutput( void ) {
	std::cout << "char: ";
	if (_charStatus == _POSSIBLE) {
		if (!std::isprint(_charValue))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << _charValue << "'" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	

	std::cout << "int: ";
	if (_intStatus == _POSSIBLE)
		std::cout << _intValue << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (_fltStatus == _POSSIBLE)
		std::cout << std::fixed << std::setprecision(2) << _fltValue << "f" << std::endl;
	else if (_fltStatus == _INF || _fltStatus == _NAN)
		std::cout  << _fltValue << 'f' << std::endl;
	else
		std::cout << "impossible" << std::endl;

	
	std::cout << "double: ";
	if (_dblStatus == _POSSIBLE)
		std::cout << std::fixed << std::setprecision(2) << _dblValue << std::endl;
	else if (_dblStatus == _INF || _dblStatus == _NAN)
		std::cout << _dblValue << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::covert( std::string input ) {
	chooseType(input);
	checkLimits(input);
	performCasting(input);
	if (_printing == true)
		printOutput();
}