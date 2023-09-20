/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 22:25:32 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
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
}

void	Cat::speak( void ) {
	std::cout << _brain->getIdea(_index - 1) << std::endl;
}