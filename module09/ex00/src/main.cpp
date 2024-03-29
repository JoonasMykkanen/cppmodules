/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:44:49 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/29 13:41:35 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main( int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Invalid number of arguments, expected [input_file]" << std::endl;
		return 1;
	}

	(void)argv;
	try {
		BitcoinExchange	btc;
		btc.loadInputFile(argv[1]);
	}
	catch(std::exception& error) {
		std::cerr << error.what() << std::endl;
		return 1;
	}

	return 0;
}