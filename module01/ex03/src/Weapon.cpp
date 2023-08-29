/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:31 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/29 09:23:13 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) { }

Weapon::~Weapon( void ) { }

void	Weapon::setType( std::string type ) {
	_type = type;
}

std::string const & Weapon::getType( void ) {
	std::string&	typeRef = _type;
	
	return (typeRef);
}