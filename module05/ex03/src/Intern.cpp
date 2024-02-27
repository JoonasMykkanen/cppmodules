/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:57:30 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/27 10:49:22 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern( void ) {
	// std::cout << "Intern default constructor called \n";
}

Intern::~Intern( void ) {
	// std::cout << "Intern default destructor called \n";
}

Intern::Intern( Intern const & other ) {
	// std::cout << "Intern copy constructor called \n";
	*this = other;
}

Intern& Intern::operator=( Intern const & other ) {
	// std::cout << "Intern copy assigment operator called \n";
	( void ) other;
	return *this;
}

AForm* Intern::makeRobotomy( std::string target ) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubbery( std::string target ) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makePresidental( std::string target ) {
	return new PresidentalPardonForm(target);
}

AForm*	Intern::makeForm( std::string const formName, std::string const targetName ) {
	std::string forms[] = {
		"RobotomyRequestForm",
		"ShrubberyCreationForm",
		"PresidentalPardonForm"
	};

	Intern::t_forms formFunctions = {
		&Intern::makeRobotomy,
		&Intern::makeShrubbery,
		&Intern::makePresidental
	};

	AForm* newForm = nullptr;
	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			newForm = (this->*formFunctions[i])(targetName);
			std::cout << "Intern creates " << formName << std::endl;
			return newForm;
		}
	}
	
	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const noexcept {
	return "Form does not exist";
}