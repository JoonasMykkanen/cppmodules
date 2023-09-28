/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 09:59:49 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include <iostream>

int main() {
    // Testing FragTrap parameterized constructor
    FragTrap frag_named("FragNamed");
    frag_named.attack("EnemyJ");
    frag_named.takeDamage(30); 
    frag_named.beRepaired(15);
    frag_named.highFivesGuys();
    std::cout << std::endl;

    // Testing FragTrap copy constructor
    FragTrap frag_copied(frag_named);
    frag_copied.attack("EnemyK");
    frag_copied.takeDamage(30); 
    frag_copied.beRepaired(20);
    frag_copied.highFivesGuys();
    std::cout << std::endl;

    // Testing FragTrap assignment operator
    FragTrap frag_assigned = frag_named;
    frag_assigned.attack("EnemyL");
    frag_assigned.takeDamage(30); 
    frag_assigned.beRepaired(25);
    frag_assigned.highFivesGuys();
    std::cout << std::endl;

    // Demonstrating energy and health depletion for FragTrap
    for (int i = 0; i < 10; i++) {
        frag_assigned.attack("EnemyL");
        frag_assigned.takeDamage(30);
    }
    std::cout << std::endl;

    // Test repairing FragTrap beyond the limit
    frag_assigned.beRepaired(200);
    std::cout << std::endl;

    return 0;
}
