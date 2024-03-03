/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:14:53 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/08 11:44:13 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm( void ) : _name("generic AForm"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm( const std::string name, const int signGrade, const int execGrade)
: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade > 150 || _execGrade > 150) {
		throw(GradeTooLowException());
	}
	if (_signGrade < 1 || _execGrade < 1) {
		throw(GradeTooHighException());
	}
}

AForm::AForm( AForm const & other )
: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	*this = other;
}

AForm&	AForm::operator=( AForm const & other ) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm( void) {}

std::string const &	AForm::getName( void ) const {
	return _name;
}

bool	AForm::getSigned( void ) const {
	return _signed;
}

void	AForm::setSigned( bool status ) {
	_signed = status;
}

int	AForm::getSignGrade( void ) const {
	return _signGrade;	
}

int	AForm::getExecGrade( void ) const {
	return _execGrade;
}

void	AForm::beSigned(Bureaucrat const & user ) {
	if ( user.getGrade() > _signGrade ) {
		throw(GradeTooLowException());
	} else {
		_signed = true;
	}
}

void	AForm::execute(Bureaucrat const & executor ) const {
	if (getSigned() == false) {
		throw NotSignedException();
	}
	else if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const noexcept {
	return "the form has not been signed";
}

std::ostream& operator<<( std::ostream& os, AForm const & obj ) {
	os << "AForm: " << obj.getName() << std::endl;
	os << "Sing grade: " << obj.getSignGrade() << std::endl;
	os << "Execute grade: " << obj.getExecGrade() << std::endl;
	os << "Signed: " << obj.getSigned() << std::endl;
	return os;
}