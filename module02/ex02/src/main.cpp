/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:27:28 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 10:56:49 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main() {
    Fixed a;            // Default constructor
    Fixed b(10);        // Int constructor
    Fixed c(20.5f);     // Float constructor
    Fixed d(b);         // Copy constructor
    a = Fixed(30);      // Assignment operator

    // Displaying initial values
    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;

    // Test getters
    std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
    std::cout << "b.getRawBits(): " << b.getRawBits() << std::endl;

    // Test setters
    a.setRawBits(15);
    std::cout << "After a.setRawBits(15), a: " << a << std::endl;

    // Test comparison operators
	std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // Test arithmetic operators
	std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
    Fixed sum = a + b;
    Fixed diff = a - b;
    Fixed prod = a * b;
    Fixed quotient = a / b;

    std::cout << "After arithmetic operations:" << std::endl;
	std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
    std::cout << "a + b: " << sum << std::endl;
    std::cout << "a - b: " << diff << std::endl;
    std::cout << "a * b: " << prod << std::endl;
    std::cout << "a / b: " << quotient << std::endl;

    // Test pre-increment/decrement
    std::cout << "Before pre-increment/decrement, a: " << a << " b: " << b << std::endl;
    ++a;
    --b;
    std::cout << "After pre-increment/decrement, a: " << a << " b: " << b << std::endl;

    // Test post-increment/decrement
    std::cout << "Before post-increment/decrement, a: " << a << " b: " << b << std::endl;
    a++;
    b--;
    std::cout << "After post-increment/decrement, a: " << a << " b: " << b << std::endl;

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

