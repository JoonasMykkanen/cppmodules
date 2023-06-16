/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:41 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/16 14:22:37 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Contact.class.hpp"

Contact::Contact( void ) {
	std::cout << "Constructor called!" << std::endl;

	Contact::_nbInst += 1;
	return ;
}

Contact::~Contact( void ) {
	std::cout << "Destructor called!" << std::endl;

	Contact::_nbInst -= 1;
	return ;
}

int	Contact::getNbInst( void ) {
	return (Contact::_nbInst);
}

int	Contact::_nbInst = 0;