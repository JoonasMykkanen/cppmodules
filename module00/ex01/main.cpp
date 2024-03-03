/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:48 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/12 09:01:39 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

void	toLowerCase(std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::tolower(static_cast<unsigned char>(str[i]));
    }
}

int	handleInput(std::string input, PhoneBook& list) {
	toLowerCase(input);
	if (input == "add") {
		list.addContact();
		return (0);
	}
	if (input == "search") {
		list.findContact();
		return (0);
	}
	if (input == "exit") {
		return (1);
	}
	return (0);
}

int	main(void) {
	std::string	input;
	PhoneBook	list;
	
	std::cout << "Welcome to aweseome phonebook!" << std::endl;
	std::cout << "Avaivable commands are: ADD, SEARCH & EXIT" << std::endl;
	while (42) {
		if (std::cin.eof()) {
            std::cin.clear();
            std::cout << "\nDont you even try... EOF detected, Exiting..." << std::endl;
            exit(1);
        }

		if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "An error occurred. Please try again." << std::endl;
        }
		
		std::cout << "Enter command--> ";
    	std::getline(std::cin, input);
		if (handleInput(input, list) == 1)
			break ;
	}

	return (0);
}