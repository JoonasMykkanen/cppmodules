/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:38:36 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 15:56:11 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

// Had to change Zombie class a bit to make allocation work
// it must have default constructor (no args) to make this work
// then set name with separate public function
// Below lines can be used to prove that it is more than one zombie
// since they all will have unique names
Zombie*	zombieHorde( int n, std::string name ) {
	Zombie* zombieHorde = new Zombie[n];
	for (int i = 0; i < n; i++) {
		// std::string baseName = name;
		// std::string uniqueName = baseName + std::to_string(i);
		// zombieHorde[i].setName(uniqueName);
		zombieHorde[i].setName(name);
	}
	return (zombieHorde);
}