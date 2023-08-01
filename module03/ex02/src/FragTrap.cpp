/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:35:57 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/28 11:40:43 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap( void ) {
	std::cout << "FragTrap default constructor called" << std::endl;
	energyPoints_ = 100;
	attackDamage_ = 30;
	health_ = 100;
	name_ = "none";
}

FragTrap::FragTrap( std::string name ) {
	std::cout << "FragTrap variable constructor called" << std::endl;
	energyPoints_ = 100;
	attackDamage_ = 30;
	health_ = 100;
	name_ = name;
}

FragTrap::FragTrap( FragTrap const & other ) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	energyPoints_ = other.energyPoints_;
	attackDamage_ = other.attackDamage_;
	health_ = other.health_;
	name_ = other.name_;
}

FragTrap& FragTrap::operator=( FragTrap const & other ) {
	std::cout << "FragTrap Equal operator overload called" << std::endl;	
	if (this != &other) {
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
		health_ = other.health_;
		name_ = other.name_;
	}
	return (*this);
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "Fragtraps positively requests highfives from claps and traps :3" << std::endl;	
}