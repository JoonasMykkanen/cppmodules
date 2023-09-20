/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 13:54:20 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( Cat const & other ) {
	std::cout << "Cat copy constructor called" << std::endl;
	_type = other._type;
}

Cat& Cat::operator=( Cat const & other ) {
	std::cout << "Cat equal operator overload called" << std::endl;	
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Meooow" << std::endl;
}