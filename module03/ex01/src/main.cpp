/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 11:37:24 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavy");
	
	std::cout << std::endl;

    // Test the attack function
    clap.attack("Scavy");
    scav.takeDamage(0);

	std::cout << std::endl;
	
    scav.attack("Clappy");
    clap.takeDamage(20);

    // Test the beRepaired function
	// clap wont heal since it is dead
    clap.beRepaired(5);
    scav.beRepaired(5);

    // Test the ScavTrap's specific function guardGate
    scav.guardGate();

	std::cout << std::endl;

    return 0;
}
