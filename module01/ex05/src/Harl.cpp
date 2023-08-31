/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:44:16 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/31 07:46:23 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
	
}

Harl::~Harl( void ) {
	
}

Harl::functionPtr Harl::getFunctionPtr( std::string level ) {
	char	c = level[0];

	switch(c) {
		case 'i':
			return (&Harl::info);
		case 'd':
			return (&Harl::debug);
		case 'e':
			return (&Harl::error);
		case 'w':
			return (&Harl::warning);
		default:
			return (NULL);
	}
}

void    complain( std::string level ) {
	Harl	func;

	Harl::functionPtr fn = func.getFunctionPtr(level);
	(func.*fn)();
}
