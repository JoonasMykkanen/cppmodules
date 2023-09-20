/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 13:54:13 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( Dog const & other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	_type = other._type;
}

Dog& Dog::operator=( Dog const & other ) {
	std::cout << "Dog equal operator overload called" << std::endl;	
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Bark bark.." << std::endl;
}