/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.HPP                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:58:29 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/31 16:43:50 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream> // TODO REMOVE

class RPN {
	
	public:
		static void	compute( std::string const & input );

	private:
		RPN();
		RPN( RPN const & other );
		RPN& operator=( RPN const & other );
		~RPN();

		static char	getNextOperator( void );
		static int	getNextOperand( void );

		static void	doMathStuff( void );
		static bool checkOperator( char c );
		static bool checkOperand( char c );
		static void processInput( std::string const & input );

		static std::stack<char>	_operators;
		static std::stack<int>	_operands;
		static int				_result;
		
};

#endif // !RPN_HPP
