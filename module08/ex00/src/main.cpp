/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:27:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/14 14:40:29 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main( void ) {
	std::cout << "Created list {0, 1 , 42, -42}" << std::endl;
	std::list<int>	ints = {0, 1 , 42, -42};

	std::cout << std::endl;

	try {
		std::cout << "running: easyfind(ints, 42);" << std::endl;
		std::cout << "expecting no errors" << std::endl;
		easyfind(ints, 42);
	}
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

	try {
		std::cout << "running: easyfind(ints, 101);" << std::endl;
		std::cout << "expecting exception since it's not found" << std::endl;
		easyfind(ints, 101);
	}
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

	std::cout << "Created vector {0, 1 , 42, -42}" << std::endl;
	std::vector<int> vec = {0, 1 , 42, -42};

	std::cout << std::endl;

	try {
		std::cout << "running: easyfind(vec, 42);" << std::endl;
		std::cout << "expecting no errors" << std::endl;
		easyfind(vec, 42);
	}
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

	try {
		std::cout << "running: easyfind(vec, 101);" << std::endl;
		std::cout << "expecting exception since it's not found" << std::endl;
		easyfind(vec, 101);
	}
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	return 0;
}