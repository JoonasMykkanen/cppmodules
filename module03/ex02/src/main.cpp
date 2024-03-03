/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/29 07:21:30 by joonasmykka      ###   ########.fr       */
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
	std::cout << "enemy gets hit by a foodtruck and recieves 800 points of damage\n";
	enemy.takeDamage(800);
	enemy.takeDamage(800);
	enemy.attack("Anyone");
    enemy.beRepaired(5);
	enemy.highFivesGuys();	
    std::cout << std::endl;

    return (0);
}
