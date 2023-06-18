/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:48 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/18 16:37:39 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.class.hpp"
#include "include/Contact.class.hpp"
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
	PhoneBook list;
	
	std::cout << "Welcome to aweseome phonebook!" << std::endl;
	std::cout << "Avaivable commands are: ADD, DELETE, SEARCH & EXIT" << std::endl;
	std::string	input;
	while (42) {
		std::cout << "Enter command--> ";
    	std::cin >> input;
		if (handleInput(input, list) == 1)
			break ;
	}

	return (0);
}