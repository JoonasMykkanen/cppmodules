/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:30:53 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/03 11:38:45 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( std::string const & type ) : 
_type(type), _equipped(false), _collected(false) {
	// std::cout << "AMateria name constructor called" << std::endl;
}

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

bool	AMateria::getEquipped() const {
	return _equipped;
}

void	AMateria::setEquipped( bool status ) {
	_equipped = status;
}

bool	AMateria::getCollected() const {
	return _collected;
}

void	AMateria::setCollected( bool status ) {
	_collected = status;
}

void	AMateria::use(ICharacter & target) {
	std::cout << target.getName();
}