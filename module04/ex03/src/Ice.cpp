/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:06:36 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 14:11:58 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice:

void	Ice::use(int idx, ICharacter& target) {
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName();
	std::cout << " *\n";
}