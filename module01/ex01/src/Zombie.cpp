/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:57 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 14:35:25 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie( void ) {

}

Zombie::~Zombie( void ) {
	
}

void	Zombie::announce( void ) {
	std::cout << this->name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}