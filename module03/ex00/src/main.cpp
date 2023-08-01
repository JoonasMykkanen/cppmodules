/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:52 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/28 10:48:51 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap char1("char1");
	ClapTrap char2("char2");

	char1.attack("char2");
	char2.takeDamage(0);
	char2.beRepaired(1);
	char2.beRepaired(2);
	char2.beRepaired(3);
	char2.beRepaired(4);
	char2.beRepaired(5);
	char2.beRepaired(6);
	char2.beRepaired(7);
	char2.beRepaired(8);
	char2.beRepaired(9);
	char2.beRepaired(10);
	char2.beRepaired(11);
	char2.attack("char1");
	std::cout << "char1 gets hit by a car!!!!\n";
	char1.takeDamage(800);
	char1.beRepaired(1);
	char1.takeDamage(0);

	return (0);
}