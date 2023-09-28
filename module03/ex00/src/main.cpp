/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 08:24:50 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) {
    // Testing ClapTrap parameterized constructor
    ClapTrap clap_named("ClapNamed");
    clap_named.attack("EnemyB");  // Should not attack since attackDamage is 0
    clap_named.takeDamage(0);
    clap_named.beRepaired(5);
    std::cout << std::endl;

    // Testing ClapTrap copy constructor
    ClapTrap clap_copied(clap_named);
    clap_copied.attack("EnemyC");  // Should not attack since attackDamage is 0
    clap_copied.takeDamage(0);
    clap_copied.beRepaired(5);
    std::cout << std::endl;

    // Testing ClapTrap assignment operator
    ClapTrap clap_assigned = clap_named;
    clap_assigned.attack("EnemyD");  // Should not attack since attackDamage is 0
    clap_assigned.takeDamage(0);
    clap_assigned.beRepaired(5);
    std::cout << std::endl;

	return (0);
}