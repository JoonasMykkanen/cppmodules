/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2024/02/26 23:00:19 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentalPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int	main( void ) {
	RobotomyRequestForm		form1("Doctors collague");
	ShrubberyCreationForm	form2("hive yard");
	PresidentalPardonForm	form3("convict");
	
	Bureaucrat 				doctor("Doctor", 1);
	Bureaucrat 				gardner("gardner", 98);
	Bureaucrat 				president("president", 1);
	Bureaucrat				student("student", 150);

	std::cout << "First sign and then execute, should work just fine" << std::endl;
	try {
		form1.beSigned(doctor);
		doctor.executeForm(form1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Trying to execute without signing, does not work" << std::endl;
	try {
		president.executeForm(form2);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Finally signing and now executing" << std::endl;
	try {
		president.signForm(form2);
		president.executeForm(form2);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Another successfull test, just with different form" << std::endl;
	try {
		president.signForm(form3);
		president.executeForm(form3);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Tring to sign and execute a form without enough grade" << std::endl;
	try {
		student.signForm(form1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		student.executeForm(form1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "trying to sign already signed form" << std::endl;
	try {
		president.signForm(form3);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}