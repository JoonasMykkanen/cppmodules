/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:27:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/14 20:33:12 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <random>

static void	pushNumbers( Span& target, size_t count ) {
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-1000000000, 1000000000);
	
	for (size_t i = 0; i < count; i++) {
		target.addNumber(distrib(gen));
	}
}

int main( void ) {
	Span sp(5);
	
	sp.addNumbers({6, 3, 17, 9, 11});

	std::cout << "subjects basic test: " << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	{
		Span sp(1000);
		pushNumbers(sp, 1000);

		std::cout << "from 1k: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp(10000);
		pushNumbers(sp, 10000);

		std::cout << "from 10k: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp(100000);
		pushNumbers(sp, 100000);

		std::cout << "from 100k: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp(1000000);
		pushNumbers(sp, 1000000);

		std::cout << "from 1m: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}