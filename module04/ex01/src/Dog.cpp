/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/04 10:53:24 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
	_type = "Dog";
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
		if (_brain)
			delete _brain;
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
	std::string idea = _brain->getIdea(_index - 1);
	if (idea.length() > 0)
		std::cout << _brain->getIdea(_index - 1) << std::endl;
	else
		std::cout << "* CRICKETS *" << std::endl;
}