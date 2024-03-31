/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:58:10 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/31 16:39:26 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "RPN.hpp"

int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << "Invalid number of parameters" << std::endl;
		return 1;
	}
	
	std::cout << "arg: " << argv[1] << std::endl;
	RPN::compute(argv[1]);

	return 0;
}