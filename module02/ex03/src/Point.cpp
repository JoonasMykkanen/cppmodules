/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:04:34 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/26 11:53:47 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : x_(Fixed(0)), y_(Fixed(0)) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point( float x, float y ) : x_(Fixed(x)), y_(Fixed(y)) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::~Point( void ) {
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(Point const & other) : x_(other.x_), y_(other.y_) {
    // std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=( Point const & other ) {
	// std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
	}
	return (*this);
}

Fixed Point::getX( void ) const {
    return this->x_;
}

Fixed Point::getY( void ) const {
    return this->y_;
}
