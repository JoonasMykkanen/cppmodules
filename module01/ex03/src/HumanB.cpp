/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:27 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/16 10:14:15 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB( std::string newName ) : _name(newName) { }

HumanB::~HumanB( void ) { }

void	HumanB::attack( void ) {
	std::string	current = _weapon->getType();
	
	if (current.empty()) {
		std::cout << _name << "does not have weapon yet..." << std::endl;
	} else {
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon( Weapon &newWeapon ) {
	_weapon = &newWeapon;
}