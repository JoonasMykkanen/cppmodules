/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/01 11:27:11 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal( void ) {
	std::cout << "Animal default constructor called" << std::endl;
	type_ = "";
}

Animal::Animal( std::string type ) {
	std::cout << "Animal variable constructor called" << std::endl;
	type_ = type;
}

Animal::Animal( Animal const & other ) {
	std::cout << "Animal copy constructor called" << std::endl;
	type_ = other.type_;
}

Animal& Animal::operator=( Animal const & other ) {
	std::cout << "Animal equal operator overload called" << std::endl;	
	if (this != &other) {
		type_ = other.type_;
	}
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType( void ) const {
	return type_;
}

void	Animal::makeSound( void ) const {}
