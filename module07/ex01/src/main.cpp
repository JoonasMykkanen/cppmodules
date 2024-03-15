/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/15 12:46:51 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <typeinfo>

// Subjects test
class Awesome {
	public:
		Awesome(void):_n(42) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get(); return o; }

template <typename Type>
void print( Type const & x) { std::cout << x << std::endl; return; }




template <typename Type>
void	function(Type arg) {
	const std::type_info& info = typeid(arg);
	static int counter = 1;
	
	std::cout << counter << ":	" << "type passed: " << info.name() << std::endl;
	counter++;
}

int	main( void ) {
	
	{
		std::cout << "Testing with ints:" << std::endl;
		int	arr[10] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
		iter(&arr, 10, function);
		std::cout << std::endl;
	}
	{
		std::cout << "Testing with chars:" << std::endl;
		char	arr[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
		iter(&arr, 10, function);
		std::cout << std::endl;
	}
	{
		std::cout << "Testing with strings:" << std::endl;
		std::string	arr[5] = { "Hello", "World", "!" };
		iter(&arr, 5, function);
	}
	{
		std::cout << "Testing with subjects:" << std::endl;
		int tab[] = { 0, 1, 2, 3, 4 };
		Awesome tab2[5];

		iter( tab, 5, print );
		iter( tab2, 5, print );
	}

	return 0;
} 