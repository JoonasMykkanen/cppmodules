/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 07:32:29 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 10:22:02 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _index(0) {
	// std::cout << "MateriaSource default consturctor called" << std::endl;
	for (int i = 0; i < FULL_MEMORY; i++) {
		_memory[i] = nullptr;
	}
}

MateriaSource::MateriaSource( MateriaSource const & other ) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < FULL_MEMORY; i++) {
		if (other._memory[i]) {
			_memory[i] = other._memory[i]->clone();
		} else {
			_memory[i] = nullptr;
		}
	}
}

MateriaSource&	MateriaSource::operator=( MateriaSource const & other ) {
	// std::cout << "MateriaSource equal overload called" << std::endl;
	if (this != &other) {
        for (int i = 0; i < FULL_MEMORY; ++i) {
            delete _memory[i];
            if (other._memory[i]) {
                _memory[i] = other._memory[i]->clone();
            } else {
                _memory[i] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource( void ) {
	// std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < FULL_MEMORY; i++) {
		if (_memory[i]) {
			delete _memory[i];
		}
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m) return;
	
	if (_index >= 0 && _index < FULL_MEMORY) {
		_memory[_index] = m;
		_index += 1;	
	} 
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < FULL_MEMORY; i++) {
		if (_memory[i] != nullptr && _memory[i]->getType() == type) {
			return _memory[i]->clone();
		}
	}
	return nullptr;
}