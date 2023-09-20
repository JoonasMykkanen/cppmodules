/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/01 12:28:38 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal( void ) {
	std::cout << "AAnimal default constructor called" << std::endl;
	_type = "";
}

AAnimal::AAnimal( std::string type ) {
	std::cout << "AAnimal variable constructor called" << std::endl;
	_type = type;
}

AAnimal::AAnimal( AAnimal const & other ) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	_type = other._type;
}

AAnimal& AAnimal::operator=( AAnimal const & other ) {
	std::cout << "AAnimal equal operator overload called" << std::endl;	
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType( void ) const {
	return _type;
}
