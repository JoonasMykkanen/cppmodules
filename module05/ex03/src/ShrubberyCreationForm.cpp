/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:14:53 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/14 16:54:05 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Color.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
: AForm( "ShrubberyCreationForm", 145, 137 ) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target )
: AForm( "ShrubberyCreationForm", 145, 137 ), _target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & other )
: AForm( "ShrubberyCreationForm", 145, 137 ), _target(other._target) {
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other ) {
	if (this != &other) {
		this->AForm::setSigned(other.getSigned());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void) {}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	AForm::execute(executor);

	std::ofstream	outFile(_target + "_shrubbery");
	
	if (outFile.fail()) {
		std::cerr << COLOR_RED << "Could not create outfile" << COLOR_RESET << std::endl;
		return;
	}

	outFile << "    x\n";
	outFile << "   / \\\n";
	outFile << "  x   x\n";
	outFile << " / \\ / \\\n";
	outFile << "x   x   x\n";
	outFile.close();
}