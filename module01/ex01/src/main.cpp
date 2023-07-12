/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:39:19 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 14:29:09 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void) {
	std::string name;
	int			count;

	std::cout << "Give two arguments, horde size N and thier name" << std::endl;
	std::cout << "Count: ";
	std::cin >> count;
	std::cout << "name: ";
	std::cin >> name;
	
	// Allocating horde of zombies, init will happen inside func
	Zombie *horde = zombieHorde(count, name);

	// Making them print their name one by one
	for (int i = 0; i < count; i++) {	
		horde[i].announce();
	}

	// free horde after usage
	delete[] horde;
	
	return (0);
}