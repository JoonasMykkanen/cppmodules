/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:57 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/08 11:31:48 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
	this->_name = name;	
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " destructor called" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
