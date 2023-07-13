/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:31 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 17:05:24 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type) {
	
}

Weapon::~Weapon( void ) {
	
}

void	Weapon::setType( std::string type ) {
	this->type = type;
}

std::string const & Weapon::getType( void ) {
	std::string	typeRef = this->type;
	return (typeRef);
}