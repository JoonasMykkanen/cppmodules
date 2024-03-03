/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:14:53 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/14 15:22:27 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentalPardonForm.hpp"
#include "../inc/Color.hpp"

PresidentalPardonForm::PresidentalPardonForm( void )
: AForm( "PresidentalPardonForm", 25, 5 ), _target("[target]") {
	
}

PresidentalPardonForm::PresidentalPardonForm( std::string const target )
: AForm( "PresidentalPardonForm", 25, 5 ), _target(target) {
	
}

PresidentalPardonForm::PresidentalPardonForm( PresidentalPardonForm const & other )
: AForm( "PresidentalPardonForm", 25, 5 ), _target(other._target) {
	*this = other;
}

PresidentalPardonForm&	PresidentalPardonForm::operator=( PresidentalPardonForm const & other ) {
	if (this != &other) {
		this->AForm::setSigned(other.getSigned());
	}
	return *this;
}

PresidentalPardonForm::~PresidentalPardonForm( void ) {}

void	PresidentalPardonForm::execute( Bureaucrat const & executor ) const {
	AForm::execute(executor);
	
	std::cout << _target << " has been pardoned by president Zaphod Beeblebrox." << std::endl;
}