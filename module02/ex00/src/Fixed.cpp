/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:56:49 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/20 06:43:51 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->value_ = 0;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & other ) {
	std::cout << "Copy constructor called" << std::endl;
	this->value_ = other.value_;
}

Fixed& Fixed::operator=(const Fixed & other) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
		this->value_ = other.value_;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value_);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value_ = raw;
}