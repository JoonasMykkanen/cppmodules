/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/15 12:32:55 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "whatever.hpp"

class Awesome {
	public:
		Awesome(void):_n(0) {}
		Awesome(int n):_n(n) {}
		Awesome &operator=(Awesome const & a) {_n = a._n; return *this; }
		bool	operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
		bool	operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
		bool	operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
		bool	operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
		bool	operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
		bool	operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
		int	get_n() const { return _n; }
		
	private:
		int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int	main( void ) {

	{
		std::cout << "--------- Subjects test case -----------" << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{	// Proving requirement for having to pass two __SAME__ type values
		// int		n = 42;
		// char	c = '*';

		// ::swap(n, c);
		// ::min(n, c);
		// ::max(n, c);
	}	// works automagically tho

	{ // proving complex types
		std::cout << "\n --------- Subjects test case -----------" << std::endl;
		Awesome a(2), b(4);
		swap(a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}

	return 0;
} 