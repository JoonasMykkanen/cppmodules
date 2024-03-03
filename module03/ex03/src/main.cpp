/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/29 07:24:36 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int main() {
	DiamondTrap enemy("enemy");
    DiamondTrap diamond_named("DiamondNamed");
	DiamondTrap diamond_copied(diamond_named);
	DiamondTrap diamond_assigned = diamond_named;
	std::cout << std::endl;

    // Testing DiamondTrap parameterized constructor
    diamond_named.attack("enemy");
    enemy.takeDamage(30); 
    enemy.beRepaired(15);
    diamond_named.guardGate();
    diamond_named.highFivesGuys();
    diamond_named.whoAmI();
    std::cout << std::endl;

    // Testing DiamondTrap copy constructor
    diamond_copied.attack("enemy");
    enemy.takeDamage(30); 
    enemy.beRepaired(20);
    diamond_copied.guardGate();
    diamond_copied.highFivesGuys();
    diamond_copied.whoAmI();
    std::cout << std::endl;

    // Testing DiamondTrap assignment operator
    diamond_assigned.attack("enemy");
    enemy.takeDamage(30); 
    enemy.beRepaired(25);
    diamond_assigned.guardGate();
    diamond_assigned.highFivesGuys();
    diamond_assigned.whoAmI();
    std::cout << std::endl;

    // Demonstrating energy and health depletion for DiamondTrap
	std::cout << "enemy gets hit by a foodtruck and recieves 800 points of damage\n";
	enemy.takeDamage(800);
	enemy.takeDamage(800);
	enemy.attack("Anyone");
    enemy.beRepaired(5);
	diamond_assigned.guardGate();
    diamond_assigned.highFivesGuys();
    diamond_assigned.whoAmI();
    std::cout << std::endl;

    // Test repairing DiamondTrap beyond the limit
    diamond_assigned.beRepaired(200);
    std::cout << std::endl;

    return 0;
}