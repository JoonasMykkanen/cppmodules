/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/11 14:23:04 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

# define EPSILION 1.0e-7

class Fixed {
	
	public:

		Fixed( void );
		Fixed( const int value );
		Fixed( const float value );
		Fixed( Fixed const & other );
		Fixed& operator=( Fixed const & other );
		~Fixed ( void );
		
		friend std::ostream& operator<<( std::ostream& os, const Fixed& obj );

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
