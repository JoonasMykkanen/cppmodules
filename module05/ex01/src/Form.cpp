/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:14:53 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/26 22:24:45 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form( void ) : _name("generic form"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form( const std::string name, const int signGrade, const int execGrade)
: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade > 150 || _execGrade > 150) {
		throw(GradeTooLowException());
	}
	if (_signGrade < 1 || _execGrade < 1) {
		throw(GradeTooHighException());
	}
}

Form::Form( Form const & other )
: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	*this = other;
}

Form&	Form::operator=( Form const & other ) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

Form::~Form( void) {}

std::string const &	Form::getName( void ) const {
	return _name;
}

bool	Form::getSigned( void ) const {
	return _signed;
}

int	Form::getSignGrade( void ) const {
	return _signGrade;	
}

int	Form::getExecGrade( void ) const {
	return _execGrade;
}

void	Form::beSigned(Bureaucrat const & user ) {
	if ( user.getGrade() > _signGrade ) {
		throw(GradeTooLowException());
	} else {
		_signed = true;
	}
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade too low";
}

std::ostream& operator<<( std::ostream& os, Form const & obj ) {
	os << "Form: " << obj.getName() << "\n";
	os << "Sing grade: " << obj.getSignGrade() << "\n";
	os << "Execute grade: " << obj.getExecGrade() << "\n";
	os << "Signed: " << obj.getSigned() << "\n";
	return os;
}