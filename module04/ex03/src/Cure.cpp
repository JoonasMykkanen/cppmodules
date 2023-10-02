/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:06:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 17:30:34 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure( Cure const & other ) : AMateria(other) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure&	Cure::operator=( Cure const & other ) {
	// std::cout << "Cure equal overload called" << std::endl;
	if (this != &other) {
		_type = other.getType();
	}
	return *this;
}

Cure::~Cure( void ) {
	// std::cout << "Cure default destructor called" << std::endl;
}

void	Cure::use( ICharacter& target ) {
	std::cout << "* heals ";
	std::cout << target.getName();
	std::cout << "'s wounds *\n";
}

AMateria*	Cure::clone() const {
	return new Cure(*this);
}