/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:24:17 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 15:54:59 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	newZombie( std::string name ) {
	if (name.length() < 1)
		return (NULL);
	
	Zombie* newZombie = new Zombie(name);
		
	return (newZombie);
};