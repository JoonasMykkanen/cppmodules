/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:23:11 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/18 07:50:16 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void) {
	// allocated to the heap with newZombie and deleted afterwards
	Zombie* PeterPan = newZombie("Heap Hepperson");
	PeterPan->announce();
	delete PeterPan;

	// allocated to the stack and deleted when function returns
	randomChump("Stack McStackitystack");

	return (0);
}