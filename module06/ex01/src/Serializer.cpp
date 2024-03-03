/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:20:42 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/03 16:27:33 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer( void ) {
	std::cout << "constructor called" << std::endl;
}

Serializer::Serializer( Serializer const & other ) {
	*this = other;
}

Serializer& Serializer::operator=( Serializer const & other ) {
	( void ) other;
	return *this;
}

Serializer::~Serializer( void ) {
	std::cout << "destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}