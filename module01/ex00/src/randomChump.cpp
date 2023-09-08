/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:24:13 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/08 11:42:27 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

void	randomChump( std::string name ) {
	if (name.length() < 1)
		return ;
	
	Zombie	newZombie(name);
	newZombie.announce();
}