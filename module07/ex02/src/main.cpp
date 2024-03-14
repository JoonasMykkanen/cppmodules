/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/14 13:23:00 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>
#include <string>

int	main( void ) {
	try {
		std::cout << "---------- Array<int>	empty; ----------" << std::endl;
		Array<int>	empty;
		std::cout << "empty.size(): " << empty.size() << std::endl;
		std::cout << "empty[0] = 42: " << std::endl;
		empty[0] = 42;
	}
	catch (std::exception& e) { std::cout << "catch: " << e.what() << std::endl; }

	std::cout << std::endl;

	try {
		std::cout << "---------- Array<char>	chars(10); ----------" << std::endl;
		Array<char>	chars(10);
		std::cout << "chars.size(): " << chars.size() << std::endl;
		std::cout << "printing before assigment (<< chars[0]): " << chars[0] << std::endl;
		chars[0] = 'a';
		std::cout << "chars[0] = 'a': " << std::endl;
		std::cout << "printing after assigment (<< chars[0]): " << chars[0] << std::endl;
		chars[0] = 'b';
		std::cout << "chars[0] = 'b': " << std::endl;
		std::cout << "printing after re assigment (<< chars[0]): " << chars[0] << std::endl;
	}
	catch (std::exception& e) { std::cout << "catch: " << e.what() << std::endl; }

	std::cout << std::endl;

	try {
		std::cout << "---------- Array<char>	chars(3); ----------" << std::endl;
		std::cout << "chars[0] = 'a': " << std::endl;
		std::cout << "chars[1] = 'b': " << std::endl;
		std::cout << "chars[2] = 'c': " << std::endl;
		Array<char>	chars(3);
		chars[0] = 'a';
		chars[1] = 'b';
		chars[2] = 'c';
		std::cout << "running for loop with (i < 10) so that array goes out of bounds" << std::endl;
		for (size_t i = 0; i < 10; i++)
			std::cout << "index: " << i << " output(chars[i]): " << chars[i] << std::endl;
	}
	catch (std::exception& e) { std::cout << "catch: " << e.what() << std::endl; }

	std::cout << std::endl;

	try {
		std::cout << "---------- Array<char>	chars(3); ----------" << std::endl;
		std::cout << "chars[0] = 'a': " << std::endl;
		std::cout << "chars[1] = 'b': " << std::endl;
		std::cout << "chars[2] = 'c': " << std::endl;
		Array<char>	chars(3);
		chars[0] = 'a';
		chars[1] = 'b';
		chars[2] = 'c';
		std::cout << "accessing chars[-1]" << std::endl;
		chars[-1] = 'a';
	}
	catch (std::exception& e) { std::cout << "catch: " << e.what() << std::endl; }

	std::cout << std::endl;

	try {
		std::cout << "---------- Array<int>		arr1(2); ----------" << std::endl;
		std::cout << "---------- const Array<int>	arr2(arr1); ----------" << std::endl;
		Array<int>	arr1(2);
		arr1[0] = 42;
		arr1[1] = 24;

		const Array<int> arr2(arr1);

		std::cout << "arr1[0]: " << arr1[0] << " arr1[1]: " << arr1[1] << std::endl;
		std::cout << "and now const arr2: " << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << " arr2[1]: " << arr2[1] << std::endl;

		std::cout << std::endl;

		std::cout << "modifying arr1 to prove that it's a deep copy, arr2 should be unchanged" << std::endl;
		std::cout << "arr1[0] = 0" << std::endl;
		std::cout << "arr1[1] = 0" << std::endl;
		arr1[0] = 0;
		arr1[1] = 0;

		std::cout << std::endl;

		std::cout << "arr1[0]: " << arr1[0] << " arr1[1]: " << arr1[1] << std::endl;
		std::cout << "and now const arr2: " << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << " arr2[1]: " << arr2[1] << std::endl;

		std::cout << std::endl;

		std::cout << "Try to modify arr2 now, you cant, it's marked as const" << std::endl;
		// arr2[0] = 0;
	}
	catch (std::exception& e) { std::cout << "catch: " << e.what() << std::endl; }

}