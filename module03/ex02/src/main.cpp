/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 12:15:36 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include <iostream>

int main() {
	FragTrap enemy("enemy");
    FragTrap fraggy("fraggy");
	FragTrap fraggyCOPY(fraggy);
	FragTrap fraggyASSIGN = fraggy;
	std::cout << std::endl;
    
    // Testing FragTrap parameterized constructor
    fraggy.attack("enemy");
    enemy.takeDamage(30);
    enemy.beRepaired(5);
    std::cout << std::endl;

    // Testing FragTrap's guardGate() method
    fraggy.highFivesGuys();
    std::cout << std::endl;

    // Testing FragTrap copy constructor
    fraggyCOPY.attack("enemy");
	enemy.takeDamage(30);
    enemy.beRepaired(5);
    std::cout << std::endl;

    // Testing FragTrap assignment operator
    fraggyASSIGN.attack("enemy");
    enemy.takeDamage(30);
    enemy.beRepaired(5);
    std::cout << std::endl;

	 // enemy is dead now
    fraggyASSIGN.attack("enemy");
    enemy.takeDamage(30);
    enemy.beRepaired(5);
    std::cout << std::endl;

	// Nothing should work after this
	std::cout << "fraggyASSIGN gets hit by a foodtruck and recieves 800 points of damage\n";
	fraggyASSIGN.takeDamage(800);
	fraggyASSIGN.takeDamage(800);
    fraggyASSIGN.beRepaired(5);
	fraggyASSIGN.highFivesGuys();
    std::cout << std::endl;

    return (0);
}
