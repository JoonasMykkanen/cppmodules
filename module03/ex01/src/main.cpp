/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 08:21:04 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Testing ScavTrap default constructor
    ScavTrap scav_default;
    scav_default.attack("EnemyE");
    scav_default.takeDamage(20); // ScavTrap has a higher health so adjust damage
    scav_default.beRepaired(10);
    scav_default.guardGate();
    std::cout << std::endl;

    // Testing ScavTrap parameterized constructor
    ScavTrap scav_named("ScavNamed");
    scav_named.attack("EnemyF");
    scav_named.takeDamage(20); // Adjust damage
    scav_named.beRepaired(15);
    scav_named.guardGate();
    std::cout << std::endl;

    // Testing ScavTrap copy constructor
    ScavTrap scav_copied(scav_named);
    scav_copied.attack("EnemyG");
    scav_copied.takeDamage(20); // Adjust damage
    scav_copied.beRepaired(20);
    scav_copied.guardGate();
    std::cout << std::endl;

    // Testing ScavTrap assignment operator
    ScavTrap scav_assigned = scav_named;
    scav_assigned.attack("EnemyH");
    scav_assigned.takeDamage(20); // Adjust damage
    scav_assigned.beRepaired(25);
    scav_assigned.guardGate();
    std::cout << std::endl;

    // Demonstrating energy and health depletions
    for (int i = 0; i < 10; i++) {
        scav_assigned.attack("EnemyH");
        scav_assigned.takeDamage(20);
    }
    std::cout << std::endl;

    scav_assigned.beRepaired(200);
    std::cout << std::endl;

    return 0;
}
