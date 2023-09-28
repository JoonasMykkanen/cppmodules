/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:50:30 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 12:27:32 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	_energyPoints = 50;
	_attackDamage = 20;
	_health = 100;
	_name = "none";
}

ScavTrap::ScavTrap( std::string name ) {
	std::cout << "ScavTrap variable constructor called" << std::endl;
	_energyPoints = 50;
	_attackDamage = 20;
	_health = 100;
	_name = name;
}

ScavTrap::ScavTrap( ScavTrap const & other ) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	_health = other._health;
	_name = other._name;
}

ScavTrap& ScavTrap::operator=( ScavTrap const & other ) {
	std::cout << "ScavTrap equal operator overload called" << std::endl;	
	if (this != &other) {
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_health = other._health;
		_name = other._name;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (_health > 0 && _energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", dealing " << _attackDamage << " points of damage!\n";
		_energyPoints -= 1;
	}
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << _name << " is guarding gate now." << std::endl;
}