/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 07:32:29 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/04 10:57:42 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _index(0) {
	// std::cout << "MateriaSource default consturctor called" << std::endl;
	for (int i = 0; i < FULL_MEMORY; i++) {
		_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const & other ) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < FULL_MEMORY; i++) {
		if (other._memory[i]) {
			_memory[i] = other._memory[i]->clone();
		} else {
			_memory[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator=( MateriaSource const & other ) {
	// std::cout << "MateriaSource equal overload called" << std::endl;
	if (this != &other) {
        for (int i = 0; i < FULL_MEMORY; ++i) {
			if (_memory[i])
            	delete _memory[i];
            if (other._memory[i]) {
                _memory[i] = other._memory[i]->clone();
            } else {
                _memory[i] = NULL;
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

// will leak if full
void	MateriaSource::learnMateria(AMateria* m) {
	if (!m) return;
	
	if (_index >= 0 && _index < FULL_MEMORY) {
		_memory[_index] = m;
		_index += 1;	
	} 
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < FULL_MEMORY; i++) {
		if (_memory[i] != NULL && _memory[i]->getType() == type) {
			AMateria* newMateria = _memory[i]->clone();
			newMateria->setEquipped(false);
			newMateria->setCollected(false);
			return newMateria;
		}
	}
	return NULL;
}