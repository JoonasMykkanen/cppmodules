/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:06:36 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/03 06:01:41 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( Ice const & other ) : AMateria(other._type) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

Ice&	Ice::operator=( Ice const & other ) {
	// std::cout << "Cure equal overload called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Ice::~Ice( void ) {
	// std::cout << "Ice default destructor called" << std::endl;
}

void	Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName();
	std::cout << " *\n";
}

AMateria*	Ice::clone() const {
	return new Ice(*this);
}