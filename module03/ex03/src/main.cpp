/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 09:52:39 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int main() {
    // Testing DiamondTrap parameterized constructor
    DiamondTrap diamond_named("DiamondNamed");
    diamond_named.attack("EnemyA");
    diamond_named.takeDamage(30); 
    diamond_named.beRepaired(15);
    diamond_named.guardGate();
    diamond_named.highFivesGuys();
    diamond_named.whoAmI();
    std::cout << std::endl;

    // Testing DiamondTrap copy constructor
    DiamondTrap diamond_copied(diamond_named);
    diamond_copied.attack("EnemyB");
    diamond_copied.takeDamage(30); 
    diamond_copied.beRepaired(20);
    diamond_copied.guardGate();
    diamond_copied.highFivesGuys();
    diamond_copied.whoAmI();
    std::cout << std::endl;

    // Testing DiamondTrap assignment operator
    DiamondTrap diamond_assigned = diamond_named;
    diamond_assigned.attack("EnemyC");
    diamond_assigned.takeDamage(30); 
    diamond_assigned.beRepaired(25);
    diamond_assigned.guardGate();
    diamond_assigned.highFivesGuys();
    diamond_assigned.whoAmI();
    std::cout << std::endl;

    // Demonstrating energy and health depletion for DiamondTrap
	std::cout << "diamond_assigned gets hit by a car!\n";
    diamond_assigned.takeDamage(1000);
	diamond_assigned.takeDamage(30); 
    diamond_assigned.beRepaired(25);
    diamond_assigned.guardGate();
    diamond_assigned.highFivesGuys();
    diamond_assigned.whoAmI();
    std::cout << std::endl;

    // Test repairing DiamondTrap beyond the limit
    diamond_assigned.beRepaired(200);
    std::cout << std::endl;

    return 0;
}