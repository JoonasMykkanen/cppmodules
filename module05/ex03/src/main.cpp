/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2024/02/27 10:49:06 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentalPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int	main( void ) {
	Bureaucrat JustPromotedFromInter("Pekka Pouta", 150);
	Bureaucrat OldSchooler("Alias Von HaffelHof", 1);
	Intern SummerInter;
	AForm* form = nullptr;
	
	form = SummerInter.makeForm("RobotomyRequestForm", "Bender");
	form->beSigned(OldSchooler);
	form->execute(OldSchooler);
	
	try {
		form->execute(JustPromotedFromInter);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	if (form != nullptr)
		delete form;
	

	
	AForm* invalidForm;
	try {
		invalidForm = SummerInter.makeForm("This form probably does not exists asdasd", "Bender");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	if (invalidForm != nullptr) {
		delete invalidForm;
	}
	
	return 0;
}