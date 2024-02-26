/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2024/02/26 22:18:14 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main( void ) {
	// Catch with general std::exception
	std::cout << "RUNNING: Bureacrat kalevi('kalevi', 100)\n";
	std::cout << "Expecting no errors. \n";
	try {
		Bureaucrat kalevi("kalevi", 100);
		Bureaucrat ville(kalevi);
		Bureaucrat tonttu = ville;
		std::cout << tonttu;
	} catch( std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Trying grade too high
	std::cout << "RUNNING: Bureacrat kalevi('kalevi', -15)\n";
	std::cout << "Expecting error grade too high. \n";
	try {
		Bureaucrat kalevi("kalevi", -15);
		std::cout << kalevi;
	} catch( Bureaucrat::GradeTooHighException & e ) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Trying grade too low
	std::cout << "RUNNING: Bureacrat kalevi('kalevi', 200)\n";
	std::cout << "Expecting error grade too low. \n";
	try {
		Bureaucrat kalevi("kalevi", 200);
		std::cout << kalevi;
	} catch( Bureaucrat::GradeTooLowException & e ) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Both "edge cases"
	std::cout << "RUNNING: Running both edge cases, max and min grade (1, 150)\n";
	try {
		Bureaucrat max("seppo", 1);
		Bureaucrat min("seppo", 150);
		std::cout << max;
		std::cout << min;
	} catch( Bureaucrat::GradeTooLowException & e ) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Proves that error is actually thrown, program will abort if no try / catch
	// Bureaucrat kalevi("kalevi", 200);
	// Bureaucrat kalevi("kalevi", -200);
	// but not with correct one
	std::cout << "Next test will need modification of main.cpp" << std::endl;
	Bureaucrat correctOne("correctOne", 100);
	// std::cout << correctOne;

	return 0;
}