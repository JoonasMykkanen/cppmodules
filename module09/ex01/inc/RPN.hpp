/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:58:29 by jmykkane          #+#    #+#             */
/*   Updated: 2024/04/11 10:14:05 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>

class RPN {
	
	public:
		static void	compute( std::string const & input );

	private:
		RPN();
		RPN( RPN const & other );
		RPN& operator=( RPN const & other );
		~RPN();

		static void	addition( int first, int second );
		static void	substact( int first, int second );
		static void	multiply( int first, int second );
		static void	division( int first, int second );

		static int	getNextNumber( void );
		static bool checkOperand( char c );
		static bool checkOperator( char c );

		static std::stack<int>	_nums;
		
};

#endif // !RPN_HPP
