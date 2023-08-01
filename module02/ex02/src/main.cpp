/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:27:28 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/20 16:35:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

#include "../inc/Fixed.hpp"

#include "../inc/Fixed.hpp"

#include "../inc/Fixed.hpp"

int main() {
    // Initializing using various constructors
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

    return 0;
}

