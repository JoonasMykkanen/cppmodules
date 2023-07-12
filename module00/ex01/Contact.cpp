/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:41 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/10 13:46:26 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Contact.hpp"

Contact::Contact( void ) {
	this->index = this->getNbInst();
	this->filled = false;
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->secret = "";

	Contact::_nbInst += 1;
	return ;
}

Contact::~Contact( void ) {
	Contact::_nbInst -= 1;
	return ;
}

int	Contact::getNbInst( void ) {
	return (Contact::_nbInst);
}

int	Contact::_nbInst = 0;