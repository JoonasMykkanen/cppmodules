/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:35:57 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/28 09:56:04 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
	_energyPoints = ::ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_health = FragTrap::_health;
	_name = "None";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
    std::cout << "DiamondTrap named constructor called" << std::endl;
    _name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other) : ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}


DiamondTrap& DiamondTrap::operator=(DiamondTrap const & other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	if (_health > 0 && _energyPoints > 0) {
    	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
	}
}
