/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:27 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 17:27:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void ) {
	
}

HumanB::~HumanB( void ) {
	
}

void	HumanB::attack( void ) {
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}