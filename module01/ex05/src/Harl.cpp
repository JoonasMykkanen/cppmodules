/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:44:16 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/18 08:10:10 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
	_funcMap["debug"] = &Harl::debug;
	_funcMap["info"] = &Harl::info;
	_funcMap["warning"] = &Harl::warning;
	_funcMap["error"] = &Harl::error;
}

Harl::~Harl( void ) { }

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void stringToLower(std::string& str) {
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        *it = std::tolower(static_cast<unsigned char>(*it));
    }
}

Harl::functionPtr Harl::getFunctionPtr( std::string level ) {
	stringToLower(level);
	std::map<std::string, functionPtr>::iterator it = _funcMap.find(level);
    if (it != _funcMap.end()) {
        return it->second;
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
