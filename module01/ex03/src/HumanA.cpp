/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:25 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 17:27:53 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( Weapon* weapon ) : weapon(weapon) {
	
}

HumanA::~HumanA( void ) {
	
}

void	HumanA::attack( void ) {
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}