/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:51 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/12 09:03:06 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

}

PhoneBook::~PhoneBook( void ) {
	
}

std::string	get_input( std::string msg ) {
	std::string	input;

	while (input.empty()) {
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

		std::cout << msg;
    	std::getline(std::cin, input);
	}
	return (input);
}

void	PhoneBook::addContact( void ) {
	static int	oldest = 0;
	std::string input;
	int index = 0;
	
	while (this->contacts[index].getFilled() == true && index < 8) {
		index++;
	}

	if (index == 8) {
		if (oldest == 8) {
			oldest = 0;
		}
		index = 0;
		index += oldest;
		oldest += 1;
	}
	
	this->contacts[index].setFirstName(get_input("Enter contact's firstname: "));
	this->contacts[index].setLastName(get_input("Enter contact's lastname: "));
	this->contacts[index].setNickName(get_input("Enter contact's nickname: "));
	this->contacts[index].setNumber(get_input("Enter contact's number: "));
	this->contacts[index].setSecret(get_input("Enter the secret: "));
	this->contacts[index].setFilled(true);
	std::cout << this->contacts[index].getFirstName() << " has added been to phonebook" << std::endl;

	return ;
}

void	PhoneBook::findContact( void ) {
	std::stringstream	ss;
	int	idx = 0;
    
    while (this->contacts[idx].getFilled() == true && idx < 8) {
		ss << this->contacts[idx].getIndex();
        std::string indexStr = ss.str();
		ss.str("");
        std::string firstName = this->contacts[idx].getFirstName();
        std::string lastName = this->contacts[idx].getLastName();
        std::string nickName = this->contacts[idx].getNickName();

        if (firstName.length() > WIDTH) 
            firstName = firstName.substr(0, WIDTH - 1) + ".";
        if (lastName.length() > WIDTH)
            lastName = lastName.substr(0, WIDTH - 1) + ".";
        if (nickName.length() > WIDTH)
            nickName = nickName.substr(0, WIDTH - 1) + ".";

        std::cout << '|' << std::setw(WIDTH) << std::right << std::setfill(' ') << indexStr
                  << '|' << std::setw(WIDTH) << std::right << std::setfill(' ') << firstName
                  << '|' << std::setw(WIDTH) << std::right << std::setfill(' ') << lastName
                  << '|' << std::setw(WIDTH) << std::right << std::setfill(' ') << nickName
                  << '|' << std::endl;
        idx++;
    }

	std::cout << "enter index: ";
	std::cin >> idx;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (std::cin.eof()) {
		std::cin.clear();
		std::cout << "\nDont you even try... EOF detected, Exiting..." << std::endl;
		exit(1);
	}

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input..." << std::endl;
	}
	else if (idx < 8 && this->contacts[idx].getFilled() == true) {
		std::cout << "firstname: " << this->contacts[idx].getFirstName() << std::endl;
		std::cout << "lastname: " << this->contacts[idx].getLastName() << std::endl;
		std::cout << "nickname: " << this->contacts[idx].getNickName() << std::endl;
		std::cout << "number: " << this->contacts[idx].getNumber() << std::endl;
		std::cout << "darkest secret: " << this->contacts[idx].getSecret() << std::endl;
	} else {
		std::cout << "No such entry" << std::endl;
	}
}
