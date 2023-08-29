/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:38:36 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/29 09:17:18 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	zombieHorde( int n, std::string name ) {
	Zombie* zombieHorde = new Zombie[n];
	for (int i = 0; i < n; i++) {
		zombieHorde[i].setName(name);
		// BELOW LINES PROVES INDIVIDUAL ZOMBIES
		// std::string baseName = name;
		// std::string uniqueName = baseName + std::to_string(i);
		// zombieHorde[i].setName(uniqueName);
	}
	return (zombieHorde);
}