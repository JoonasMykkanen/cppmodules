/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:39:19 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/18 07:57:03 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void) {
	std::string name;
	int			count;

	// Case without name yet
	Zombie	zomb;
	zomb.announce();

	std::cout << "Give two arguments, horde size N and thier name" << std::endl;
	std::cout << "Count: ";
	std::cin >> count;
	std::cout << "name: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, name);
	
	// Check if input is valid
	if (count < 1 || name.empty()) {
		std::cout << "error with input" << std::endl;
		return (0);
	}

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