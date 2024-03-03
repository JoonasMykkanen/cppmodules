/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:57 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/18 07:54:10 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie( void ) {

}

Zombie::~Zombie( void ) {
	
}

void	Zombie::announce( void ) {
	if (this->_name.length() > 0) {
		std::cout << this->_name;
		std::cout << ": BraiiiiiiinnnzzzZ...\n"; 
	} else {
		std::cout << "This brain eater is uninitalized..\n";
	}
}

void	Zombie::setName( std::string newName ) {
	this->_name = newName;
}