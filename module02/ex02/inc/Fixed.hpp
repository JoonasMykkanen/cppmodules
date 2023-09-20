/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 09:59:09 by joonasmykka      ###   ########.fr       */
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

		// Comparisons
		bool operator>( const Fixed& other ) const;
		bool operator<( const Fixed& other ) const;
		bool operator>=( const Fixed& other ) const;
		bool operator<=( const Fixed& other ) const;
		bool operator==( const Fixed& other ) const;
		bool operator!=( const Fixed& other ) const;

		// Arithmetic
		Fixed operator+( const Fixed& other ) const;
		Fixed operator-( const Fixed& other ) const;
		Fixed operator*( const Fixed& other ) const;
		Fixed operator/( const Fixed& other ) const;

		// Overloaded min / max functions
		static Fixed&	min( Fixed& point1, Fixed& point2 );
		static Fixed&	max( Fixed& point1, Fixed& point2 );
		static const Fixed&	min( const Fixed& point1, const Fixed& point2 );
		static const Fixed&	max( const Fixed& point1, const Fixed& point2 );
		
		// 	Increment / decrement
		Fixed&	operator++( void );		// pre-increment	(++i)
		Fixed	operator++( int );		// post-increment	(i++)
		Fixed&	operator--( void );		// pre-decrement	(--i)
		Fixed	operator--( int );		// post-decrement	(i--)

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
