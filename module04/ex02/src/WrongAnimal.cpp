/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:34:28 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 22:26:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	_type = "";
}

WrongAnimal::WrongAnimal( std::string type ) {
	std::cout << "Wronganimal variable constructor called" << std::endl;
	_type = type;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	_type = other._type;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const & other ) {
	std::cout << "WrongAnimal equal operator overload called" << std::endl;	
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return _type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Base class sounds brrrrr" << std::endl;
}
