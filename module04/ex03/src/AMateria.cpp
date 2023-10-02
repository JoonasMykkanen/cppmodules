/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:30:53 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 08:39:07 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( std::string const & type ) : _type(type) {
	// std::cout << "AMateria default constructor called" << std::endl;
}

// TODO OTHER IS NOT CORRECT
AMateria::AMateria( AMateria const & other ) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	_type = other._type;
}

AMateria& AMateria::operator=( AMateria const & other ) {
	// std::cout << "AMateria equal operator overload called" << std::endl;	
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria( void ) {
	// std::cout << "AMateria default destructor called" << std::endl;
}

std::string const &	AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter & target) {
	std::cout << target.getName();
}