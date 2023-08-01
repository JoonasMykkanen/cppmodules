/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 13:24:34 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	type_ = "Dog";
}

Dog::Dog( Dog const & other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	type_ = other.type_;
}

Dog& Dog::operator=( Dog const & other ) {
	std::cout << "Dog equal operator overload called" << std::endl;	
	if (this != &other) {
		type_ = other.type_;
	}
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Bark bark.." << std::endl;
}