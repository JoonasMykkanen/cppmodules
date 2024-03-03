/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:20:36 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/03 16:27:44 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main( void ) {
	Data d1 = { .num = 42 };
	
	uintptr_t ser = Serializer::serialize(&d1);
	Data *ptr = Serializer::deserialize(ser);

	std::cout << "--------------------Checking addressess--------------------" << std::endl;
	std::cout << "address of struct:	" << &d1 << std::endl;
	std::cout << "deserialized ptr:	" << ptr << std::endl;

	std::cout << std::endl;

	std::cout << "--------------------Checking values--------------------" << std::endl;
	std::cout << "value of struct:	" << d1.num << std::endl;
	std::cout << "deserialized value:	" << ptr->num << std::endl;
	
	return 0;
}