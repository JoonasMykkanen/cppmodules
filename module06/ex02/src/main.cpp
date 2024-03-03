/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:32:00 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/03 17:56:52 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <random>

#include "main.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "B.hpp"
#include "A.hpp"

static int	get_random_number( void ) {
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 3);

	return dist(gen);
}

Base*	generate( void ) {
	int 	random = get_random_number();
	Base*	ptr = nullptr;

	switch(random) {
		case _A:
			ptr = new A();
			break;
			
		case _B:
			ptr = new B();
			break;

		case _C:
			ptr = new C();
			break;

		default:
			return nullptr;
	}

	const char list[4] = "ABC";
	std::cout << "Random class instanciated of type: <" << list[random - 1] << ">" << std::endl;
	
	return ptr;
}

void	identify( Base* p ) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "<A>" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "<B>" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "<C>" << std::endl;
	}
	else {
		std::cout << "Could not find a type for <Base* p>" << std::endl;
	}
}

void identify( Base& p ) {
	Base object;

	try {
		object = dynamic_cast<A&>(p);
		std::cout << "<A>" << std::endl;
	}
	catch(std::exception&e) {}

	try {
		object = dynamic_cast<B&>(p);
		std::cout << "<B>" << std::endl;
	}
	catch(std::exception&e) {}

	try {
		object = dynamic_cast<C&>(p);
		std::cout << "<C>" << std::endl;
	}
	catch(std::exception&e) {}
}



int	main( void ) {
	Base* ptr = generate();

	std::cout << "Identifying by ptr: ";
	identify(ptr);

	std::cout << "Identifying by ref: ";
	identify(*ptr);

	if (ptr)
		delete ptr;
	
	return 0;
}