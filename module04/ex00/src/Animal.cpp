/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 09:05:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) {
	std::cout << "Animal default constructor called" << std::endl;
	_type = "None";
}

Animal::Animal( std::string type ) {
	std::cout << "Animal variable constructor called" << std::endl;
	_type = type;
}

Animal::Animal( Animal const & other ) {
	std::cout << "Animal copy constructor called" << std::endl;
	_type = other._type;
}

Animal& Animal::operator=( Animal const & other ) {
	std::cout << "Animal equal operator overload called" << std::endl;	
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType( void ) const {
	return _type;
}

void	Animal::makeSound( void ) const {
	std::cout << "ambiguous animal sounds.." << std::endl;
}
