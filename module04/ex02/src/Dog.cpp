/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 13:31:20 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
	_index = 0;
}

Dog::Dog( Dog const & other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
	_index = other._index;
	_type = other._type;
}

Dog& Dog::operator=( Dog const & other ) {
	std::cout << "Dog equal operator overload called" << std::endl;	
	if (this != &other) {
		_brain = new Brain(*other._brain);
		_index = other._index;
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound( void ) const {
	std::cout << "Bark bark.." << std::endl;
}

void	Dog::think( std::string tought ) {
	_brain->setIdea(_index, tought);
	_index++;
	if (_index == 99 ) {
		_index = 0;
	}
}

void	Dog::speak( void ) {
	std::cout << _brain->getIdea(_index - 1) << std::endl;
}