/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:30:36 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/19 22:53:33 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

char	ScalarConverter::_charValue = 0;
int	ScalarConverter::_charStatus = 1;

double	ScalarConverter::_dblValue = 0;
int	ScalarConverter::_dblStatus = 1;

float	ScalarConverter::_fltValue = 0;
int	ScalarConverter::_fltStatus = 1;

int		ScalarConverter::_intValue = 0;
int	ScalarConverter::_intStatus = 1;

int		ScalarConverter::_type = NoneType;
bool	ScalarConverter::_negative = false;
bool	ScalarConverter::_printing = true;
int		ScalarConverter::_precision = 1;


ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( ScalarConverter const & other ) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const & other ) {
	( void ) other;
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}


// ----------  convert() helper functions ---------- //

static int	countPrecision( std::string const & input ) {
	size_t	startPos = input.find('.');
	if (startPos == std::string::npos) {
		return 1;
	}

	std::string	decimals = input.substr(startPos + 1);
	size_t len = decimals.length();

	if (input.back() == 'f')
		len--;

	return len;
}

void	ScalarConverter::chooseType( std::string const & input ) {
	if (input.empty()) {
		_type = ErrorType;
	}
	else if (!input.compare("-inff") || !input.compare("inff") || !input.compare("nanf")) {
		if (input[0] == '-')
			_negative = true;
		_type = FltType;
		_charStatus = IMPOSSIBLE;
		_intStatus = IMPOSSIBLE;
		_fltStatus = PSEUDO;
		_dblStatus = PSEUDO;
	}
	else if (!input.compare("-inf") || !input.compare("inf") || !input.compare("nan")) {
		if (input[0] == '-')
			_negative = true;
		_type = DblType;
		_charStatus = IMPOSSIBLE;
		_intStatus = IMPOSSIBLE;
		_fltStatus = PSEUDO;
		_dblStatus = PSEUDO;
	}
	else if (input.find('.') != std::string::npos && input.back() == 'f') {
		_type = FltType;
		_charStatus = POSSIBLE;
		_intStatus = POSSIBLE;
		_fltStatus = POSSIBLE;
		_dblStatus = POSSIBLE;
	}
	else if (input.find('.') != std::string::npos) {
		_type = DblType;
		_charStatus = POSSIBLE;
		_intStatus = POSSIBLE;
		_fltStatus = POSSIBLE;
		_dblStatus = POSSIBLE;
	}
	else if (input.size() == 1 && std::isprint(input[0])) {
		_type = CharType;

		_charStatus = POSSIBLE;
		_intStatus = POSSIBLE;
		_fltStatus = POSSIBLE;
		_dblStatus = POSSIBLE;
	}
	else {
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
		_charStatus = POSSIBLE;
		_intStatus = POSSIBLE;
		_fltStatus = POSSIBLE;
		_dblStatus = POSSIBLE;
	}
}

void	ScalarConverter::convertInt( std::string const & input ) {
	try
	{
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
		_intStatus = IMPOSSIBLE;
	}
}

void	ScalarConverter::convertChar( std::string const & input ) {
	try
	{
		_charValue = input[0];

		if (_intStatus)
			_intValue = static_cast<int>(_charValue);
		if (_fltStatus)
			_fltValue = static_cast<float>(_charValue);
		if (_dblStatus)
			_dblValue = static_cast<double>(_charValue);
	}
	catch (std::exception &e)
	{
		std::cout << "stoc error catched _charValue: " << _charValue <<  " input: " << input << std::endl;
	}
}

void	ScalarConverter::convertFloat( std::string const & input ) {
	try
	{
		if (_fltStatus == PSEUDO) {
			if (_negative)
				_fltValue = -std::numeric_limits<float>::infinity();
			else
				_fltValue = std::numeric_limits<float>::infinity();
		}
		else
			_fltValue = std::stod(input);
			_precision = countPrecision(input);

		if (_intStatus)
			_intValue = static_cast<int>(_fltValue);
		if (_dblStatus)
			_dblValue = static_cast<double>(_fltValue);
		if (_charStatus)
			_charValue = static_cast<char>(_fltValue);
	}
	catch (std::exception &e)
	{
		_fltStatus = IMPOSSIBLE;
	}
}

void	ScalarConverter::convertDouble( std::string const & input ) {
	try
	{
		if (_dblStatus == PSEUDO) {
			if (_negative)
				_fltStatus = -std::numeric_limits<double>::infinity();
			else
				_dblValue = std::numeric_limits<double>::infinity();
		}
		else
		{
			_dblValue = std::stod(input);
			_precision = countPrecision(input);
		}

		if (_intStatus)
			_intValue = static_cast<int>(_charValue);
		if (_charStatus)
			_charValue = static_cast<char>(_intValue);
		if (_fltStatus)
			_fltValue = static_cast<float>(_charValue);
	}
	catch (std::exception &e)
	{
		_dblStatus = IMPOSSIBLE;
	}
}

// TODO: remove prints
void ScalarConverter::performCasting( std::string const & input ) {
	switch (_type) {
		case CharType:
			std::cout << "chose char\n";
			convertChar(input);
			break;

		case IntType:
		std::cout << "chose int\n";
			convertInt(input);
			break;

		case FltType:
			std::cout << "chose flt\n";
			convertFloat(input);
			break;
		
		case DblType:
			std::cout << "chose dbl\n";
			convertDouble(input);
			break;
		
		default:
			std::cout << "Error with input." <<  " input: " << input << std::endl;
			_printing = false;
			break;
	}
}

void ScalarConverter::printOutput( void ) {
	std::cout << "char: ";
	if (_charStatus == POSSIBLE) {
		if (!std::isprint(_charValue))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << _charValue << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	

	std::cout << "int: ";
	if (_intStatus == POSSIBLE)
		std::cout << _intValue << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (_fltStatus == POSSIBLE || PSEUDO)
		std::cout << std::fixed << std::setprecision(_precision) << _fltValue << "f" << std::endl;
	else if (_fltStatus == PSEUDO)
		std::cout  << _fltValue << std::endl;
	else
		std::cout << "impossible" << std::endl;

	
	std::cout << "double: ";
	if (_dblStatus == POSSIBLE)
		std::cout << std::fixed << std::setprecision(_precision) << _dblValue << std::endl;
	else if (_dblStatus == PSEUDO)
		std::cout << _dblValue << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::covert( std::string input ) {
	chooseType(input);
	performCasting(input);
	if (_printing == true)
		printOutput();
}