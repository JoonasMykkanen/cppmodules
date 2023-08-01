/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/01 11:51:53 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	ideas_ = new Brain();
	index_ = 0;
}

Cat::Cat( Cat const & other ) {
	std::cout << "Cat copy constructor called" << std::endl;
	ideas_ = new Brain(*other.ideas_);
	index_ = other.index_;
	type_ = other.type_;
}

Cat& Cat::operator=( Cat const & other ) {
	std::cout << "Cat equal operator overload called" << std::endl;	
	if (this != &other) {
		ideas_ = new Brain(*other.ideas_);
		index_ = other.index_;
		type_ = other.type_;
	}
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete ideas_;
}

void	Cat::makeSound( void ) const {
	std::cout << "Meooow" << std::endl;
}

void	Cat::think( std::string tought ) {
	ideas_->setIdea(index_, tought);
	index_++;
}

void	Cat::speak( void ) {
	std::cout << ideas_->getIdea(index_ - 1) << std::endl;
}