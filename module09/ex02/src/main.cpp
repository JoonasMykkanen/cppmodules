/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:34:34 by jmykkane          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:04 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	error( std::string message ) {
	std::cerr << "Error: " << message << std::endl;
	return (true);
}

bool	not_valid_num(std::string str)
{
	if (str.empty()) {
		return error("non-numeric character.");
	}

	if (str.at(0) == '-') {
		return error("only positive numbers.");
	}

	for (size_t i = 0; i != str.size(); i++) {
		if (!isdigit(str.at(i)))
			return error("non-numeric character.");
	}

	try {
		size_t num = std::stoul(str);
		if (num > INT_MAX || num < 0)
			return error("Out of range for integers.");
	}
	catch(std::exception& e) {
		return error("Invalid int");
	}
	
	return (false);
}

bool	validate_input(char** argv) {
	for (size_t i = 0; argv[i]; i++) {
		if (not_valid_num(argv[i]))
			return (true);
	}
	
	return (false);
}

int main(int argc, char **argv) {
	if (argc < 2 || validate_input(argv + 1)) {
		return 0;
	}
	
	PmergeMe<std::vector<int>, pairvect>	vectorMerge(argc - 1, argv + 1);
	vectorMerge.sort();
	PmergeMe<std::deque<int>, pairdeque>	dequeMerge(argc - 1, argv + 1);
	dequeMerge.sort();
	
	vectorMerge.printOriginal();
	vectorMerge.printSorted();
	
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : ";
	vectorMerge.timeDiff();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : ";
	dequeMerge.timeDiff();
	
	return 0;
}