/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:36 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/12 13:21:14 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char **argv ) {
	
	if (argc == 2) {
		ScalarConverter::covert(argv[1]);
	}
	else {
		std::cout << "Invalid number of arguments!" << std::endl;
	}

	return 0;
}