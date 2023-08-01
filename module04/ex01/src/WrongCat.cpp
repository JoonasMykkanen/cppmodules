/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 13:56:21 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & other ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	type_ = other.type_;
}

WrongCat& WrongCat::operator=( WrongCat const & other ) {
	std::cout << "WrongCat equal operator overload called" << std::endl;	
	if (this != &other) {
		type_ = other.type_;
	}
	return (*this);
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "WrongCat meooow" << std::endl;
}