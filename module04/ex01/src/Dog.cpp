/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/01 11:52:35 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	ideas_ = new Brain();
}

Dog::Dog( Dog const & other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	ideas_ = new Brain(*other.ideas_);
	index_ = other.index_;
	type_ = other.type_;
}

Dog& Dog::operator=( Dog const & other ) {
	std::cout << "Dog equal operator overload called" << std::endl;	
	if (this != &other) {
		ideas_ = new Brain(*other.ideas_);
		index_ = other.index_;
		type_ = other.type_;
	}
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete ideas_;
}

void	Dog::makeSound( void ) const {
	std::cout << "Bark bark.." << std::endl;
}

void	Dog::think( std::string tought ) {
	ideas_->setIdea(index_, tought);
	index_++;
}

void	Dog::speak( void ) {
	std::cout << ideas_->getIdea(index_ - 1) << std::endl;
}