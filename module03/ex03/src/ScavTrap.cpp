/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:50:30 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/28 11:27:20 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	energyPoints_ = 50;
	attackDamage_ = 20;
	health_ = 100;
	name_ = "none";
}

ScavTrap::ScavTrap( std::string name ) {
	std::cout << "ScavTrap variable constructor called" << std::endl;
	energyPoints_ = 50;
	attackDamage_ = 20;
	health_ = 100;
	name_ = name;
}

ScavTrap::ScavTrap( ScavTrap const & other ) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	energyPoints_ = other.energyPoints_;
	attackDamage_ = other.attackDamage_;
	health_ = other.health_;
	name_ = other.name_;
}

ScavTrap& ScavTrap::operator=( ScavTrap const & other ) {
	std::cout << "ScavTrap equal operator overload called" << std::endl;	
	if (this != &other) {
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
		health_ = other.health_;
		name_ = other.name_;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (health_ > 0 && energyPoints_ > 0) {
		std::cout << "ScavTrap " << name_ << " attacks " << target << ", dealing " << attackDamage_ << " points of damage!\n";
		energyPoints_ -= 1;
	}
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap is guarding gate now." << std::endl;
}