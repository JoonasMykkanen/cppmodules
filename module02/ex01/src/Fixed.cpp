/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:56:49 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/11 14:23:39 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed( const int value ) : _value(value << _fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) {
	std::cout << "Float constructor called" << std::endl;
	float	shifted = _factor * value;
	_value = static_cast<int>(roundf(shifted));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & other ) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed& Fixed::operator=( const Fixed & other ) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / _factor);
}

int	Fixed::toInt( void ) const {
	return (_value >> _fractional_bits);
}

// Operator overloads || overwrite default behaviour
std::ostream& operator<<( std::ostream& os, const Fixed& obj ) {
	os << static_cast<float>(obj.toFloat());
	return (os);
}