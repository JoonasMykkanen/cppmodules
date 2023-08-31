/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:51 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/31 07:26:51 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

}

PhoneBook::~PhoneBook( void ) {
	
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
	
	std::cout << "Enter contact's firstname: ";
	std::cin >> input;
	this->contacts[index].setFirstName(input);
	std::cout << "Enter contact's lastname: ";
	std::cin >> input;
	this->contacts[index].setLastName(input);
	std::cout << "Enter contact's nickname: ";
	std::cin >> input;
	this->contacts[index].setNickName(input);
	std::cout << "Enter contact's number: ";
	std::cin >> input;
	this->contacts[index].setNumber(input);
	std::cout << "Enter the secret: ";
	std::cin >> input;
	this->contacts[index].setSecret(input);
	this->contacts[index].setFilled(true);
	std::cout << this->contacts[index].getFirstName() << " has added been to phonebook" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
	std::ostringstream	ss;
	std::string 		str;
	int					idx;

	idx = 0;
	while (this->contacts[idx].getFilled() == true && idx < 8) {
		ss << this->contacts[idx].getIndex();
		fill(&str, ss.str());
		fill(&str, this->contacts[idx].getFirstName());
		fill(&str, this->contacts[idx].getLastName());
		fill(&str, this->contacts[idx].getNickName());
		std::cout << str << std::endl;
		str.clear();
		ss.str("");
		ss.clear(); 
		idx++;
	}

	std::cout << "enter index: ";
	std::cin >> idx;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
