/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:04:34 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/19 18:07:43 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x(Fixed(0)), _y(Fixed(0)) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point( float x, float y ) : _x(Fixed(x)), _y(Fixed(y)) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::~Point( void ) {
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(Point const & other) : _x(other._x), _y(other._y) {
    // std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=( Point const & other ) {
	// std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
	}
	return (*this);
}

Fixed Point::getX( void ) const {
    return this->_x;
}

Fixed Point::getY( void ) const {
    return this->_y;
}
