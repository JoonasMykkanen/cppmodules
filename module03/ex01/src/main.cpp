/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/29 07:19:16 by joonasmykka      ###   ########.fr       */
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
	enemy.takeDamage(20);
    enemy.beRepaired(5);
    std::cout << std::endl;

    // Testing ScavTrap assignment operator
    scavASSIGN.attack("enemy");
    enemy.takeDamage(20);
    enemy.beRepaired(5);
    std::cout << std::endl;

	// Nothing should work after this
	std::cout << "enemy gets hit by a foodtruck and recieves 800 points of damage\n";
	enemy.takeDamage(800);
	enemy.takeDamage(800);
	enemy.attack("Anyone");
    enemy.beRepaired(5);
	enemy.guardGate();
    std::cout << std::endl;

    return (0);
}