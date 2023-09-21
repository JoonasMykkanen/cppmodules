/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/21 07:12:35 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>
		
std::ostream& operator<<( std::ostream& os, const class Fixed& obj );

class Fixed {
	
	public:

		Fixed( void );
		Fixed( const int value );
		Fixed( const float value );
		Fixed( Fixed const & other );
		Fixed& operator=( Fixed const & other );
		~Fixed ( void );
		

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:

		static const int	_fractional_bits = 8;
		static const int	_factor = 1 << _fractional_bits;
		int 				_value;
	
};

#endif // !FIXED_H
