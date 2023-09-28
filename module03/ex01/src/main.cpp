/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 12:11:14 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main() {
    ScavTrap enemy("enemy");
    ScavTrap scavvy("Scavvy");
	ScavTrap scavvyCOPY(scavvy);
	ScavTrap scavASSIGN = scavvy;
	std::cout << std::endl;
    
    // Testing ScavTrap parameterized constructor
    scavvy.attack("enemy");
    enemy.takeDamage(20);
    enemy.beRepaired(5);
    std::cout << std::endl;

    // Testing ScavTrap's guardGate() method
    scavvy.guardGate();
    std::cout << std::endl;

    // Testing ScavTrap copy constructor
    scavvyCOPY.attack("enemy");
    enemy.beRepaired(5);
    std::cout << std::endl;

    // Testing ScavTrap assignment operator
    scavASSIGN.attack("enemy");
    enemy.takeDamage(20);
    enemy.beRepaired(5);
    std::cout << std::endl;

	// Nothing should work after this
	std::cout << "scavASSIGN gets hit by a foodtruck and recieves 800 points of damage\n";
	scavASSIGN.takeDamage(800);
	scavASSIGN.takeDamage(800);
    scavASSIGN.beRepaired(5);
	scavvy.guardGate();
    std::cout << std::endl;

    return (0);
}