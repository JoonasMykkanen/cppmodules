/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:04:59 by jmykkane          #+#    #+#             */
/*   Updated: 2024/04/02 10:36:07 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>

int main( int argc, char** argv ) {
	if (argc == 1) {
		return 0;
	}

	try {
		std::vector<unsigned int>	tester;
		for (int i = 1; i < argc; i++) {
			if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos) {
				throw std::invalid_argument("Error: only positive ingegers allowed!");
			}
			unsigned long value = std::stoul(argv[i]);
			if (value > INT_MAX)
				throw std::invalid_argument("Error: value too big!");
		}
	}
	catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
		return 1;
	}

	{
		PmergeMe	sorter;
		sorter.sortList(argc, argv);
		
	}
	std::cout << std::endl;	
	{
		PmergeMe	sorter;
		sorter.sortVector(argc, argv);
	}
	
	return 0;
}