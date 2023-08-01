/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:34:28 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 13:49:17 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	type_ = "";
}

WrongAnimal::WrongAnimal( std::string type ) {
	std::cout << "Wronganimal variable constructor called" << std::endl;
	type_ = type;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type_ = other.type_;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const & other ) {
	std::cout << "WrongAnimal equal operator overload called" << std::endl;	
	if (this != &other) {
		type_ = other.type_;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return type_;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Base class sounds brrrrr" << std::endl;
}
