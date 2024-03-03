/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/04 10:59:54 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat( void ) {
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
	_type = "Cat";
	_index = 0;
}

Cat::Cat( Cat const & other ) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
	_index = other._index;
	_type = other._type;
}

Cat& Cat::operator=( Cat const & other ) {
	std::cout << "Cat equal operator overload called" << std::endl;	
	if (this != &other) {
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
		_index = other._index;
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound( void ) const {
	std::cout << "Meooow" << std::endl;
}

void	Cat::think( std::string tought ) {
	_brain->setIdea(_index, tought);
	_index++;
	if (_index == 99 ) {
		_index = 0;
	}
}

void	Cat::speak( void ) {
	std::string idea = _brain->getIdea(_index - 1);
	if (idea.length() > 0)
		std::cout << _brain->getIdea(_index - 1) << std::endl;
	else
		std::cout << "* CRICKETS *" << std::endl;
}