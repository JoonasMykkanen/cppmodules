/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:56:49 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/20 14:21:34 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	value_ = 0;
}

Fixed::Fixed( const int value ) : value_(value << fractional_bits_) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) {
	std::cout << "Float constructor called" << std::endl;
	float	shifted = factor_ * value;
	value_ = static_cast<int>(roundf(shifted));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & other ) {
	std::cout << "Copy constructor called" << std::endl;
	value_ = other.value_;
}

Fixed& Fixed::operator=( const Fixed & other ) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
		value_ = other.value_;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value_);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	value_ = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(value_) / factor_);
}

int	Fixed::toInt( void ) const {
	return (value_ >> fractional_bits_);
}

// Operator overloads || overwrite default behaviour
std::ostream& operator<<( std::ostream& os, const Fixed& obj ) {
	os << static_cast<float>(obj.toFloat());
	return (os);
}