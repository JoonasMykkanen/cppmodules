/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:31 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/18 08:00:40 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon( std::string newType ) : _type(newType) { }

Weapon::~Weapon( void ) { }

void	Weapon::setType( std::string newType ) {
	_type = newType;
}

std::string const & Weapon::getType( void ) {
	std::string&	typeRef = _type;
	
	return (typeRef);
}