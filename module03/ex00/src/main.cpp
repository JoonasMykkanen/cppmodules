/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 12:10:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) {

    ClapTrap enemy("enemy");
    ClapTrap clappy("clappy");
	ClapTrap clappyCOPY(clappy);
	ClapTrap clappyASSIGN = clappy;
	std::cout << std::endl;
    
    // Testing ClapTrap parameterized constructor
    clappy.attack("enemy");
    enemy.takeDamage(0);
    enemy.beRepaired(5);
    std::cout << std::endl;

    // Testing ClapTrap copy constructor
    clappyCOPY.attack("enemy");
	enemy.takeDamage(0);
    enemy.beRepaired(5);
    std::cout << std::endl;

    // Testing ClapTrap assignment operator
    clappyASSIGN.attack("enemy");
    enemy.takeDamage(0);
    enemy.beRepaired(5);
    std::cout << std::endl;

	// Nothing should work after this
	std::cout << "clappyASSIGN gets hit by a foodtruck and recieves 800 points of damage\n";
	clappyASSIGN.takeDamage(800);
	clappyASSIGN.takeDamage(800);
    clappyASSIGN.beRepaired(5);
    std::cout << std::endl;

	return (0);
}