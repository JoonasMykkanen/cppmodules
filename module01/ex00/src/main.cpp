/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:23:11 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/06 00:00:01 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void) {
	// allocated to the heap with newZombie and deleted afterwards
	Zombie* PeterPan = newZombie("Heap");
	PeterPan->announce();

	// allocated to the stack and deleted when function returns
	randomChump("Stack");

	delete PeterPan;
	return (0);
}