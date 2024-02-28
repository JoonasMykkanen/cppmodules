/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:52:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/27 23:17:21 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <limits>
# include <iostream>
# include <float.h>
# include <iomanip>
# include <string>

# define _IMPOSSIBLE 0
# define _POSSIBLE 1
# define _INF 3
# define _NAN 4

class ScalarConverter {

	public:
		static void covert( std::string input );

	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const & other );
		ScalarConverter& operator=( ScalarConverter const & other );
		~ScalarConverter( void );

		// ----------  convert() helper functions ---------- //
		static void	performCasting( std::string const & input );
		static void	checkLimits( std::string const & input );
		static void	chooseType( std::string const & input );
		static void	printOutput( void );

		static void	convertInt( std::string const & input );
		static void	convertChar( std::string const & input );
		static void	convertFloat( std::string const & input );
		static void	convertDouble( std::string const & input );
		static void convertEdgeCases( std::string const & input );

		static char		_charValue;
		static int		_charStatus;

		static double	_dblValue;
		static int		_dblStatus;

		static float	_fltValue;
		static int		_fltStatus;

		static int		_intValue;
		static int		_intStatus;

		static int		_type;
		static bool		_negative;
		static bool		_printing;

		enum	eTypes {
			CharType,
			IntType,
			FltType,
			DblType,
			ErrorType,
			NoneType
		};
			
};

#endif // !SCALAR_HPP