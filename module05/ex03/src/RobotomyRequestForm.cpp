/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:14:53 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/14 15:06:21 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Color.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
: AForm( "RobotomyRequestForm", 72, 45 ), _target("[target]") {
	
}

RobotomyRequestForm::RobotomyRequestForm( std::string const target )
: AForm( "RobotomyRequestForm", 72, 45 ), _target(target) {
	
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & other )
: AForm( "RobotomyRequestForm", 72, 45 ), _target(other._target) {
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm const & other ) {
	if (this != &other) {
		this->AForm::setSigned(other.getSigned());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void) {}

static bool	getRandomBool( void ) {
	srand(time(NULL));
	int probability = std::rand();

	if (probability % 2)
		return true;
	else
		return false;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	AForm::execute(executor);
	
	if (getRandomBool()) {
		std::cout << _target << " has been" << COLOR_GREEN << " succesfully " << COLOR_RESET << "robotomized" << std::endl;
	}
	else {
		std::cout << "Robotomy" << COLOR_RED << " failed" << COLOR_RESET << std::endl;
	}
}