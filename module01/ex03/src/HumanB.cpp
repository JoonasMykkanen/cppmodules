/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:27 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/08 12:16:07 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB( std::string newName ) : _name(newName) {
	_weapon = NULL;
}

HumanB::~HumanB( void ) { }

void	HumanB::attack( void ) {
	if (this->_weapon == NULL) {
		std::cout << _name << " does not have weapon yet..." << std::endl;
	} else {
		std::string	current = _weapon->getType();
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon( Weapon &newWeapon ) {
	_weapon = &newWeapon;
}