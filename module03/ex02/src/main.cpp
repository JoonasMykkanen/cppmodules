/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/25 10:32:46 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include <iostream>

int main()
{
	// Create an instance of FragTrap
    FragTrap frag1("Frag1");
    FragTrap frag2("Frag2");

	std::cout << std::endl;

    // Testing attack
    frag1.attack("Frag2");
    frag2.takeDamage(30);

	std::cout << std::endl;

    // Testing takeDamage
    frag2.attack("Frag1");
    frag1.takeDamage(30);

	std::cout << std::endl;

    // Testing beRepaired
    frag1.beRepaired(10);
    frag2.beRepaired(5);

    frag1.highFivesGuys();

	std::cout << std::endl;

    return 0;
}
