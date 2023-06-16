/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:41 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/16 08:50:15 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Contact.class.hpp"
#include <iostream>

Contact::Contact( void ) {
	std::cout << "Constructor called!" << std::endl;
	return;
}

Contact::~Contact( void ) {
	std::cout << "Destructor called!" << std::endl;
	return;
}