/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/28 11:43:59 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include <iostream>

int main()
{
	// Create an instance of FragTrap
    FragTrap frag1("Frag1");
    FragTrap frag2("Frag2");

    // Testing attack
    frag1.attack("Frag2");
    frag2.takeDamage(30);

    // Testing takeDamage
    frag2.attack("Frag1");
    frag1.takeDamage(30);

    // Testing beRepaired
    frag1.beRepaired(10);
    frag2.beRepaired(5);

    frag1.highFivesGuys();

    return 0;
}
