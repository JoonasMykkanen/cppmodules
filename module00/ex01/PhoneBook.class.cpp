/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:51 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/16 08:50:26 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook( void ) {
	std::cout << "Constructor called!" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void ) {
	std::cout << "Destructor called!" << std::endl;
	return;
}