/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:58:32 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/29 09:19:16 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string 	stringVAR = "HI THIS IS BRAIN";
	std::string*	stringPTR = &stringVAR;
	std::string&	stringREF = stringVAR;

	std::cout << "address of var: " << &stringVAR << std::endl;
	std::cout << "address of ptr: " << stringPTR << std::endl;
	std::cout << "address of ref: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "value of var: " << stringVAR << std::endl;
	std::cout << "value of ptr: " << *stringPTR << std::endl;
	std::cout << "value of ref: " << stringREF << std::endl;

	return (0);
}