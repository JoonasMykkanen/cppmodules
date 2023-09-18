/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:38:36 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/18 07:56:49 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

// BELOW LINES PROVES INDIVIDUAL ZOMBIES
// Make note, to_string is c++11 function
// that is why it is not in use now and only
// included to give easy way to test zombies
// with different names
// std::string baseName = name;
// std::string uniqueName = baseName + std::to_string(i);
// zombieHorde[i].setName(uniqueName);

Zombie*	zombieHorde( int n, std::string name ) {
	Zombie* zombieHorde = new Zombie[n];
	for (int i = 0; i < n; i++) {
		zombieHorde[i].setName(name);
	}
	return (zombieHorde);
}