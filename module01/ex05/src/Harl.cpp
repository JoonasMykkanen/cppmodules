/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:44:16 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 14:43:45 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
	_nameMap[0] = "debug";
	_nameMap[1] = "info";
	_nameMap[2] = "warning";
	_nameMap[3] = "error";
	_ptrMap[0] = &Harl::_debug;
	_ptrMap[1] = &Harl::_info;
	_ptrMap[2] = &Harl::_warning;
	_ptrMap[3] = &Harl::_error;
}

Harl::~Harl( void ) { }

void Harl::_debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::_info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::_warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::StringToLower(std::string& str) {
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        *it = std::tolower(static_cast<unsigned char>(*it));
    }
}

Harl::functionPtr Harl::getFunctionPtr( std::string level ) {
	Harl::StringToLower(level);
	
	for (int idx = 0; idx < MAP_LEN; idx++) {
		if (level == _nameMap[idx]) {
			return _ptrMap[idx];
		}
	}
    return NULL;
}

void	Harl::complain( std::string level ) {
	functionPtr fn = getFunctionPtr(level);
	
	if (fn != NULL) {
		std::cout << level << ": ";
		(this->*fn)();
	} else {
		std::cerr << "Invalid method of complaining, you cant even do that can you!? Sincerely -Harl\n"; 
	}
}
