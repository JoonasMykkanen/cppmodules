/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2024/02/26 22:31:09 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main( void ) {
	Form nuclearLaunchForm("Fire_All_Nuclear_Weapons", 1, 1);
	std::cout << nuclearLaunchForm << std::endl;
	std::cout << std::endl;
	
	// Trying to sign a form that with too low grade
	std::cout << "Trying to sign a form that with too low grade" << std::endl;
	Bureaucrat Trainee("Summer Trainee", 150);
	std::cout << Trainee << std::endl;
	try {
		Trainee.signForm(nuclearLaunchForm);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	
	// Now signing it with sufficent powers
	std::cout << std::endl;
	std::cout << "Now signing it with sufficent powers" << std::endl;
	try {
		Bureaucrat Sauli("Sauli", 1);
		std::cout << Sauli << std::endl;
		Sauli.signForm(nuclearLaunchForm);
		std::cout << nuclearLaunchForm << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Above max
	std::cout << "trying to create invalid froms" << std::endl;
	try {
		Form notValidForm("not valid", 0, 0);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Below min
	try {
		Form notValidForm("not valid", 500, 500);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}