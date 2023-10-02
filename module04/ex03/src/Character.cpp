	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   Character.cpp                                      :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2023/10/02 05:39:15 by joonasmykka       #+#    #+#             */
	/*   Updated: 2023/10/02 17:14:25 by joonasmykka      ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "Character.hpp"

	Character::Character( std::string const & name ) : _name(name), _garbageIndex(0) {
		// std::cout << "Character default constructor called" << std::endl;
		std::memset(_garbage, 0, sizeof(_garbage));
		for (int i = 0; i < MAX_INVENTORY; i++) {
			_inventory[i] = NULL;
		}

	}

	Character::Character( Character const & other ) : _name(other._name), _garbageIndex(0) {
		// std::cout << "Character copy constructor called" << std::endl;
		std::memset(_garbage, 0, sizeof(_garbage));
		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (other._inventory[i]) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}

	Character&	Character::operator=( Character const & other ) {
		// std::cout << "Character equal overload called" << std::endl;
		if (this != &other) {
			_name = other._name;
			for (int i = 0; i < MAX_INVENTORY; i++) {
				delete _inventory[i];
				if (other._inventory[i]) {
					_inventory[i] = other._inventory[i]->clone();
				} else {
					_inventory[i] = nullptr;
				}
			}
		}
		return *this;
	}

	Character::~Character( void ) {
		// std::cout << "Character default destructor called" << std::endl;
		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
			}
		}
		for (int i = 0; i < _garbageIndex; i++) {
        	delete _garbage[i];
   		}
	}

	std::string const &	Character::getName( void ) const {
		return _name;
	}

	void	Character::equip( AMateria *m ) {
		if (!m) return;
		
		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (_inventory[i] == NULL) {
				std::cout << "* " << _name << " equipped new " << m->getType() << " *\n";
				_inventory[i] = m;
				break;
			}
		}
	}

	void	Character::unequip( int idx ) {
		if (idx >= 0 && idx < MAX_INVENTORY) {
			std::cout << "* " << _name << " unequipped their " << _inventory[idx]->getType() << " *\n";
			_garbage[_garbageIndex] = _inventory[idx];
			_inventory[idx] = NULL;
			_garbageIndex++;
		}
	}

	void	Character::use( int idx, ICharacter& target ) {
		if (_inventory[idx]) {
			_inventory[idx]->use(target);
		}
	}