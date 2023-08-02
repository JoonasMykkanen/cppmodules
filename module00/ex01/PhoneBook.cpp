/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:51 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/02 10:56:42 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

}

PhoneBook::~PhoneBook( void ) {
	
}

void	PhoneBook::addContact( void ) {	
	int index = 0;
	
	while (this->contacts[index].filled == true) {
		index++;
	}
	std::cout << "index: " << index << std::endl;

	while (index > 0) {
		this->contacts[index].firstName = this->contacts[index - 1].firstName;
		this->contacts[index].lastName = this->contacts[index - 1].lastName;
		this->contacts[index].nickName = this->contacts[index - 1].nickName;
		this->contacts[index].secret = this->contacts[index - 1].secret;
		if (this->contacts[index].firstName.length() > 0) {
			std::cout << "set filled true: " << index << std::endl;
			this->contacts[index].filled = true;
		}
		index--;
	}
	
	std::cout << "Enter contact's firstname: ";
	std::cin >> this->contacts[0].firstName;
	std::cout << "Enter contact's lastname: ";
	std::cin >> this->contacts[0].lastName;
	std::cout << "Enter contact's nickname: ";
	std::cin >> this->contacts[0].nickName;
	std::cout << "Enter the secret: ";
	std::cin >> this->contacts[0].secret;
	this->contacts[0].filled = true;
	std::cout << this->contacts[0].firstName;
	std::cout << " has added been to phonebook" << std::endl;
	
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
	int			idx;
	
	std::cout << "Please enter entry to search for: ";
	std::cin >> idx;

	if (idx < LENGTH && this->contacts[idx].filled == true) {
		fill(&str, std::to_string(this->contacts[idx].index));
		fill(&str, this->contacts[idx].firstName);
		fill(&str, this->contacts[idx].lastName);
		fill(&str, this->contacts[idx].nickName);
		std::cout << str << std::endl;
	} else {
		std::cout << "No such entry..." << std::endl;
	}
	return ;
}
