/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:58:10 by jmykkane          #+#    #+#             */
/*   Updated: 2024/04/11 10:14:08 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << "Invalid number of parameters" << std::endl;
		return 1;
	}
	
	try {
		RPN::compute(argv[1]);
	}
	catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}

	return 0;
}