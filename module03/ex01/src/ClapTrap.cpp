/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:48:15 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/29 07:14:21 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
	_energyPoints = 10;
	_attackDamage = 0;
	_health = 10;
	_name = "None";
}

ClapTrap::ClapTrap( std::string name ) {
	std::cout << "ClapTrap Variable constructor called" << std::endl;
	_energyPoints = 10;
	_attackDamage = 0;
	_health = 10;
	_name = name;
}

ClapTrap::ClapTrap( ClapTrap const & other ) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	_health = other._health;
	_name = other._name;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & other ) {
	std::cout << "ClapTrap equal operator overload called" << std::endl;	
	if (this != &other) {
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_health = other._health;
		_name = other._name;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string& target ) {
	if (_health > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", dealing " << _attackDamage << " points of damage!\n";
		_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (_health > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";
		_health -= amount;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (_health > 0 && _energyPoints > 0) {
		_health += amount;
		std::cout << "ClapTrap " << _name << " repairs, healing " << amount << " and has " << _health << "\n";
		_energyPoints -= 1;
	}
}