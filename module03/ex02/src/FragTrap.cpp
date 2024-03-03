/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:35:57 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 12:11:44 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap( void ) {
	std::cout << "FragTrap default constructor called" << std::endl;
	_energyPoints = 100;
	_attackDamage = 30;
	_health = 100;
	_name = "None";
}

FragTrap::FragTrap( std::string name ) {
	std::cout << "FragTrap variable constructor called" << std::endl;
	_energyPoints = 100;
	_attackDamage = 30;
	_health = 100;
	_name = name;
}

FragTrap::FragTrap( FragTrap const & other ) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	_health = other._health;
	_name = other._name;
}

FragTrap& FragTrap::operator=( FragTrap const & other ) {
	std::cout << "FragTrap Equal operator overload called" << std::endl;	
	if (this != &other) {
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_health = other._health;
		_name = other._name;
	}
	return (*this);
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	if (_health > 0 && _energyPoints > 0) {
		std::cout << "Fragtrap "<< _name << " positively requests highfives from claps and traps :3" << std::endl;
	}
}