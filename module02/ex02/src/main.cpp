/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:27:28 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/21 07:31:03 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main() {
    Fixed a;            // Default constructor
    Fixed b(10);        // Int constructor
    Fixed c(20.5f);     // Float constructor
    Fixed d(b);         // Copy constructor
    a = Fixed(300.5f);      // Assignment operator

    // Displaying initial values
    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
	std::cout << std::endl;

    // Test comparison operators
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << std::endl;

    // Test arithmetic operators
	std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
    Fixed sum = a + b;
    Fixed diff = a - b;
    Fixed prod = a * b;
    Fixed quotient = a / b;
    std::cout << "a + b: " << sum << std::endl;
    std::cout << "a - b: " << diff << std::endl;
    std::cout << "a * b: " << prod << std::endl;
    std::cout << "a / b: " << quotient << std::endl;
	std::cout << std::endl;

    // Test pre-increment/decrement
	Fixed	test(10);
	std::cout << "Testing test and after incrementing and decrementing\n";
	if (test++ > 10)
		std::cout << "SHOULD NOT BE HERE\n";
	else
		std::cout << "incremented after comparison original 10 and now: " << test << std::endl;
	std::cout << "comparing: if (--test == 10)\n";
	if (--test == 10)
		std::cout << "true\n";
	else
		std::cout << "SHOUDL NOT BE HERE\n";
	std::cout << "comparing: if (++test > 10)\n";
	if (++test > 10)
		std::cout << "true\n";
	else
		std::cout << "SHOUDL NOT BE HERE\n";
	std::cout << "test now " << test << " and gonna test if (test-- < 10) should return false\n";
	if (test-- < 10)
		std::cout << "SHOULD NOT BE HERE\n";
	else
		std::cout << "false\n";
	std::cout << "final value should be the original 10 --> " << test << std::endl;
	std::cout << std::endl;

    // Test conversion to float and int
    std::cout << "c.toFloat(): " << c.toFloat() << std::endl;
    std::cout << "d.toInt(): " << d.toInt() << std::endl;

	// test min and max functions
	std::cout << std::endl;
	std::cout << "Testing min max" << std::endl;
	std::cout << "a is: " << a.toFloat() << " b is: " << b.toFloat() << std::endl;
	std::cout << "USING MIN: " << Fixed::min(a, b) << std::endl;
	std::cout << "USING MAX: " << Fixed::max(a, b) << std::endl;
	
	// test const min max
	std::cout << std::endl;
	std::cout << "and with CONST min max" << std::endl;
	const Fixed	test1(10);
	const Fixed	test2(15);
	std::cout << "a is: " << test1.toFloat() << " b is: " << test2.toFloat() << std::endl;
	std::cout << "USING MIN: " << Fixed::min(test1, test2) << std::endl;
	std::cout << "USING MAX: " << Fixed::max(test1, test2) << std::endl;
	std::cout << std::endl;

	std::cout << "trying division by zero" << std::endl;
	Fixed test5(5);
	Fixed test3(0);
	Fixed test4(10);
	try {
		test5 = test4 / test3;
	}
	catch (std::exception e){ }
	std::cout << test5 << std::endl;
    return 0;
}

