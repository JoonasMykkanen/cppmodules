/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:32:44 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 22:22:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( Brain const & other ) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=( Brain const & other ) {
	std::cout << "Brain equal operator overload called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
        	_ideas[i] = other._ideas[i];
        }
	}
	return (*this);
}

Brain::~Brain( void ) {
	std::cout << "Brain default destructor called" << std::endl;
}

void	Brain::setIdea( int index, std::string idea ) {
	if (index >= 0 && index <= 100) {
		_ideas[index] = idea;
	} else {
		std::cout << "No such index in this brain" << std::endl;
	}
}

std::string	Brain::getIdea( int index ) {
	if (index >= 0 && index <= 100) {
		return _ideas[index];
	} else {
		std::cout << "No such index in this brain" << std::endl;
		return "";
	}
}