/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:09 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/04 10:52:21 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat( void ) {
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const & other ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = other._type;
}

WrongCat& WrongCat::operator=( WrongCat const & other ) {
	std::cout << "WrongCat equal operator overload called" << std::endl;	
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "WrongCat meooow" << std::endl;
}