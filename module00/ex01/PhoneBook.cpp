/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:51 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/02 20:21:39 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

}

PhoneBook::~PhoneBook( void ) {
}

void	PhoneBook::addContact( void ) {	
	int index = 0;
	
	while (this->contacts[index].getFilled() == true) {
		index++;
	}

	while (index-- > 0) {
		this->contacts[index].setFirstName(this->contacts[index - 1].getFirstName());
		this->contacts[index].setLastName(this->contacts[index - 1].getLastName());
		this->contacts[index].setNickName(this->contacts[index - 1].getNickName());
		this->contacts[index].setNumber(this->contacts[index - 1].getNumber());
		this->contacts[index].setSecret( this->contacts[index - 1].getSecret());
		if (this->contacts[index].getFirstName().length() > 0) {
			this->contacts[index].setFilled(true);
		}
	}

	std::string	input;
	
	std::cout << "Enter contact's firstname: ";
	std::cin >> input;
	this->contacts[0].setFirstName(input);
	std::cout << "Enter contact's lastname: ";
	std::cin >> input;
	this->contacts[0].setLastName(input);
	std::cout << "Enter contact's nickname: ";
	std::cin >> input;
	this->contacts[0].setNickName(input);
	std::cout << "Enter contact's number: ";
	std::cin >> input;
	this->contacts[0].setNumber(input);
	std::cout << "Enter the secret: ";
	std::cin >> input;
	this->contacts[0].setSecret(input);
	this->contacts[0].setFilled(true);
	std::cout << this->contacts[0].getFirstName() << " has added been to phonebook" << std::endl;
	
	return ;
}

void	fill(std::string* str, std::string content) {
	unsigned int	len = content.length();
	unsigned int	offset = WIDTH - len;

	str->push_back('|');
	if (len > WIDTH) {
		content.resize(WIDTH - 1);
		content.push_back('.');
	}
	for (int i = 0; i < (int)offset; i++) {
		str->push_back(' ');
	}
	str->append(content);
	if (str->length() > LAST_ITEM) {
		str->push_back('|');
	}
}

void	PhoneBook::findContact( void ) {
	std::string str;
	int		idx = 0;
	
	while (this->contacts[idx].getFilled() == true) {
		fill(&str, std::to_string(this->contacts[idx].getIndex()));
		fill(&str, this->contacts[idx].getFirstName());
		fill(&str, this->contacts[idx].getLastName());
		fill(&str, this->contacts[idx].getNickName());
		std::cout << str << std::endl;
		idx++;
	}

	std::cout << "enter index: ";
	std::cin >> idx;

	if (this->contacts[idx].getFilled() == true) {
		std::cout << "firstname: " << this->contacts[idx].getFirstName() << std::endl;
		std::cout << "lastname: " << this->contacts[idx].getLastName() << std::endl;
		std::cout << "nickname: " << this->contacts[idx].getNickName() << std::endl;
		std::cout << "number: " << this->contacts[idx].getNumber() << std::endl;
		std::cout << "darkest secret: " << this->contacts[idx].getSecret() << std::endl;
	} else {
		std::cout << "No such entry" << std::endl;
	}

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input..." << std::endl;
	}
}
