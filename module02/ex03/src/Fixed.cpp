/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:56:49 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/26 09:24:52 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void ) {
	// std::cout << "Default constructor called" << std::endl;
	value_ = 0;
}

Fixed::Fixed( const int value ) : value_(value << fractional_bits_) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) {
	// std::cout << "Float constructor called" << std::endl;
	float	shifted = factor_ * value;
	value_ = static_cast<int>(roundf(shifted));
}

Fixed::~Fixed( void ) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & other ) {
	// std::cout << "Copy constructor called" << std::endl;
	value_ = other.value_;
}

Fixed& Fixed::operator=( Fixed const & other ) {
	// std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
		value_ = other.value_;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (value_);
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
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

bool operator>( const Fixed& point1, const Fixed& point2 ) {
	if (point1.value_ > point2.value_) {
		return true;
	} else {
		return false;
	}
}

bool operator<( const Fixed& point1, const Fixed& point2 ) {
	if (point1.value_ < point2.value_) {
		return true;
	} else {
		return false;
	}
}

bool operator>=( const Fixed& point1, const Fixed& point2 ) {
	if (point1.value_ >= point2.value_) {
		return true;
	} else {
		return false;
	}
}

bool operator<=( const Fixed& point1, const Fixed& point2 ) {
	if (point1.value_ <= point2.value_) {
		return true;
	} else {
		return false;
	}
}

bool operator==( const Fixed& point1, const Fixed& point2 ) {
	if (point1.value_ == point2.value_) {
		return true;
	} else {
		return false;
	}
}

bool operator!=( const Fixed& point1, const Fixed& point2 ) {
	if (point1.value_ != point2.value_) {
		return true;
	} else {
		return false;
	}
}

Fixed operator+( const Fixed& point1, const Fixed& point2 ) {
	Fixed	res;
	res.setRawBits(point1.getRawBits() + point2.getRawBits());
	return (res);
}

Fixed operator-( const Fixed& point1, const Fixed& point2 ) {
	Fixed	res;
	res.setRawBits(point1.getRawBits() - point2.getRawBits());
	return (res);
}

Fixed operator*( const Fixed& point1, const Fixed& point2 ) {
	Fixed	res;
	res.setRawBits((point1.getRawBits() * point2.getRawBits()) >> res.fractional_bits_);
	return (res);
}

Fixed operator/( const Fixed& point1, const Fixed& point2 ) {
	Fixed	res;
	res.setRawBits((point1.getRawBits() << res.fractional_bits_) / point2.getRawBits());
	return (res);
}

Fixed& Fixed::operator++( void ) {
	this->value_ += (1 << this->fractional_bits_);
	return (*this);
}

Fixed& Fixed::operator--( void ) {
	this->value_ -= (1 << this->fractional_bits_);
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	original;
	original.value_ = this->value_;
	this->value_ += (1 << this->fractional_bits_);
	return (original);
}

Fixed	Fixed::operator--( int ) {
	Fixed	original;
	original.value_ = this->value_;
	this->value_ -= (1 << this->fractional_bits_);
	return (original);
}