/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:41 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/02 19:46:34 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Contact.hpp"

Contact::Contact( void ) {
	this->index = this->getNbInst();
	this->filled = false;
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->number = "";
	this->secret = "";

	Contact::_nbInst += 1;
}

Contact::~Contact( void ) {
	Contact::_nbInst -= 1;
}

std::string	Contact::getSecret( void ) {
	return this->secret;
}

std::string	Contact::getNumber( void ) {
	return this->number;
}

std::string	Contact::getLastName( void ) {
	return this->lastName;
}

std::string	Contact::getNickName( void ) {
	return this->nickName;
}

std::string	Contact::getFirstName( void ) {
	return this->firstName;
}

int	Contact::getIndex( void ) {
	return this->index;
}

bool		Contact::getFilled( void ) {
	return this->filled;
}

void	Contact::setIndex( int var ) {
	this->index = var;
}

void	Contact::setFilled( bool var ){
	this->filled = var;
}

void	Contact::setSecret( std::string var ) {
	this->secret = var;
}

void	Contact::setNumber( std::string var ) {
	this->number = var;
}

void	Contact::setLastName( std::string var ) {
	this->lastName = var;
}

void	Contact::setNickName( std::string var ) {
	this->nickName = var;
}

void	Contact::setFirstName( std::string var ) {
	this->firstName = var;
}


int	Contact::getNbInst( void ) {
	return (Contact::_nbInst);
}

int	Contact::_nbInst = 0;