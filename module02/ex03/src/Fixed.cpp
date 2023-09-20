/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:56:49 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 10:59:00 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void ) {
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed( const int value ) : _value(value << _fractional_bits) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) {
	// std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(value *  _factor));
}

Fixed::~Fixed( void ) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & other ) {
	// std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed& Fixed::operator=( const Fixed & other ) {
	// std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (_factor));
}

int	Fixed::toInt( void ) const {
	return (_value >> _fractional_bits);
}

// Operator overloads || overwrite default behaviour
std::ostream& operator<<( std::ostream& os, const class Fixed& obj ) {
	os << obj.toFloat();
	return (os);
}

bool Fixed::operator>( const Fixed& other ) const {
	return (_value > other._value);
}

bool Fixed::operator<( const Fixed& other ) const {
	return (_value < other._value);
}

bool Fixed::operator>=( const Fixed& other ) const {
	return (_value >= other._value);
}

bool Fixed::operator<=( const Fixed& other ) const {
	return (_value <= other._value);
}

bool Fixed::operator==( const Fixed& other ) const {
	return (_value == other._value);
}

bool Fixed::operator!=( const Fixed& other ) const {
	return (_value != other._value);
}

Fixed Fixed::operator+( const Fixed& other ) const {
	Fixed	result(*this);
	result._value += other._value;
	return (result);
}

Fixed Fixed::operator-( const Fixed& other ) const {
	Fixed	result(*this);
	result._value -= other._value;
	return (result);
}

Fixed Fixed::operator*( const Fixed& other ) const {
	Fixed	result(*this);
	result._value = (result._value * other._value) >> _fractional_bits;
	return (result);
}

Fixed Fixed::operator/( const Fixed& other ) const {
	if (other._value == 0) {
		std::cerr << "Error: Division by zero\n";
		throw std::runtime_error("Division by zero");
	}
	Fixed	result(*this);
	result._value = (result._value << _fractional_bits) / other._value;
	return (result);
}

Fixed& Fixed::operator++( void ) {
	_value += _factor;
	return (*this);
}

Fixed& Fixed::operator--( void ) {
	_value -= _factor;
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	original(*this);
	 _value += _factor;
	return (original);
}

Fixed	Fixed::operator--( int ) {
	Fixed	original(*this);
	 _value -= _factor;
	return (original);
}

Fixed&	Fixed::min( Fixed& point1, Fixed& point2 ) {
	if (point1 < point2) {
		return point1;
	} else {
		return point2;
	}
}

Fixed&	Fixed::max( Fixed& point1, Fixed& point2 ) {
	if (point1 > point2) {
		return point1;
	} else {
		return point2;
	}
}

const Fixed&	Fixed::min( const Fixed& point1, const Fixed& point2 ) {
	if (point1 < point2) {
		return point1;
	} else {
		return point2;
	}
}

const Fixed&	Fixed::max( const Fixed& point1, const Fixed& point2 ) {
	if (point1 > point2) {
		return point1;
	} else {
		return point2;
	}
}