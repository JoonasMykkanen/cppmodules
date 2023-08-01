/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:48:15 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 11:38:37 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	energyPoints_ = 10;
	attackDamage_ = 0;
	health_ = 10;
	name_ = "none";
}

ClapTrap::ClapTrap( std::string name ) {
	std::cout << "ClapTrap variable constructor called" << std::endl;
	energyPoints_ = 10;
	attackDamage_ = 0;
	health_ = 10;
	name_ = name;
}

ClapTrap::ClapTrap( ClapTrap const & other ) {
	std::cout << "Copy constructor called" << std::endl;
	energyPoints_ = other.energyPoints_;
	attackDamage_ = other.attackDamage_;
	health_ = other.health_;
	name_ = other.name_;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & other ) {
	std::cout << "Equal operator overload called" << std::endl;	
	if (this != &other) {
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
		health_ = other.health_;
		name_ = other.name_;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string& target ) {
	if (health_ > 0 && energyPoints_ > 0) {
		std::cout << "ClapTrap " << name_ << " attacks " << target << ", dealing " << attackDamage_ << " points of damage!\n";
		energyPoints_ -= 1;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (health_ > 0 && energyPoints_ > 0) {
		std::cout << "ClapTrap " << name_ << " takes " << amount << " points of damage!\n";
		health_ -= amount;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (health_ > 0 && energyPoints_ > 0) {
		std::cout << "ClapTrap " << name_ << " repairs, healing " << amount << " and has " << health_ << "\n";
		energyPoints_ -= 1;
		health_ += amount;
	}
}
