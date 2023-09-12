/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:41 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/12 08:23:15 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Contact.hpp"

Contact::Contact( void ) {
	this->_index = this->getNbInst();
	this->_filled = false;
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_number = "";
	this->_secret = "";

	Contact::_nbInst += 1;
}

Contact::~Contact( void ) {
	Contact::_nbInst -= 1;
}

std::string	Contact::getSecret( void ) {
	return this->_secret;
}

std::string	Contact::getNumber( void ) {
	return this->_number;
}

std::string	Contact::getLastName( void ) {
	return this->_lastName;
}

std::string	Contact::getNickName( void ) {
	return this->_nickName;
}

std::string	Contact::getFirstName( void ) {
	return this->_firstName;
}

int	Contact::getIndex( void ) {
	return this->_index;
}

bool		Contact::getFilled( void ) {
	return this->_filled;
}

void	Contact::setIndex( int var ) {
	this->_index = var;
}

void	Contact::setFilled( bool var ){
	this->_filled = var;
}

void	Contact::setSecret( std::string var ) {
	this->_secret = var;
}

void	Contact::setNumber( std::string var ) {
	this->_number = var;
}

void	Contact::setLastName( std::string var ) {
	this->_lastName = var;
}

void	Contact::setNickName( std::string var ) {
	this->_nickName = var;
}

void	Contact::setFirstName( std::string var ) {
	this->_firstName = var;
}


int	Contact::getNbInst( void ) {
	return (Contact::_nbInst);
}

int	Contact::_nbInst = 0;