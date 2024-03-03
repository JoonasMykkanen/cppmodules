/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:29 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/08 12:16:39 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int	main(void) {
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Super duper club");
		bob.attack();
		
	}
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("More dangerous club");
		jim.attack();
	}

	// EXTRA TESTS
	HumanB	joonas("Joonas");
	Weapon	someWeapon("atleast some weapon");
	joonas.attack();
	joonas.setWeapon(someWeapon);
	joonas.attack();

	return (0);
}