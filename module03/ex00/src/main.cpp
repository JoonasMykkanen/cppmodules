/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 11:24:26 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap bob("bob");
	ClapTrap lisa("lisa");

	bob.attack("lisa");
	lisa.takeDamage(0);
	lisa.beRepaired(1);
	lisa.beRepaired(2);
	lisa.beRepaired(3);
	lisa.beRepaired(4);
	lisa.beRepaired(5);
	lisa.beRepaired(6);
	lisa.beRepaired(7);
	lisa.beRepaired(8);
	lisa.beRepaired(9);
	lisa.beRepaired(10);
	lisa.beRepaired(11);
	lisa.attack("bob");
	std::cout << "bob gets hit by a car!!!!\n";
	bob.takeDamage(800);
	bob.beRepaired(1);
	bob.takeDamage(0);

	return (0);
}