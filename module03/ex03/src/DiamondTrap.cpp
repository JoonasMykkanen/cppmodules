/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:35:57 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 11:23:48 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
	energyPoints_ = ::ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
	health_ = FragTrap::health_;
	name_ = "none";
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
    std::cout << "DiamondTrap named constructor called" << std::endl;
    name_ = name;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        name_ = other.name_;
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
    std::cout << "My name is " << name_ << " and my ClapTrap name is " << ClapTrap::name_ << std::endl;
}
