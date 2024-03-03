/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:30:54 by joonasmykka       #+#    #+#             */
/*   Updated: 2024/02/26 23:00:33 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

std::ostream& operator<<( std::ostream& os, Bureaucrat const & obj ) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
	return os;
}

Bureaucrat::Bureaucrat( void ) : _name("OfficeClerk"), _grade(150) {
	// std::cout << "Bureaucrat default constructor called \n";
}

Bureaucrat::Bureaucrat( std::string const & newName, int newGrade )
: _name(newName), _grade(newGrade) {
	// std::cout << "Bureaucrat parameter constructor called \n";
	if (_grade < GRADE_HIGH) {
		throw (GradeTooHighException());
	}
	if (_grade > GRADE_LOW) {
		throw (GradeTooLowException());
	}
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat default destructor called \n";
}

Bureaucrat::Bureaucrat( Bureaucrat const & other ) : _name(other.getName()) {
	// std::cout << "Bureaucrat copy constructor called \n";
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const & other ) {
	// std::cout << "Bureaucrat copy assigment operator called \n";
	if (this != &other) {
		_grade = other.getGrade();
	}
	return *this;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

std::string const & Bureaucrat::getName() const {
	return _name;
}

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < GRADE_HIGH) {
		throw (GradeTooHighException());
	}
	_grade -= 1;
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > GRADE_LOW) {
		throw (GradeTooLowException());
	}
	_grade += 1;
}

void Bureaucrat::signForm( AForm& form ) {
	if (form.getSigned()) {
		std::cout << _name << " noticed that form: " << form.getName() << " is already signed and took a coffee break" << std::endl;
		return ;
	}

	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << _name << " can't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const & form ) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << _name << " can't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade too low";
}