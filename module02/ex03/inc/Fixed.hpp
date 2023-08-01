/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/26 09:37:05 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
	
	public:

		Fixed( void );
		Fixed( const int value );
		Fixed( const float value );
		Fixed( Fixed const & other );
		Fixed& operator=( Fixed const & other );
		~Fixed ( void );
		
		friend std::ostream& operator<<( std::ostream& os, const Fixed& obj );
		friend bool operator>( const Fixed& point1, const Fixed& point2 );
		friend bool operator<( const Fixed& point1, const Fixed& point2 );
		friend bool operator>=( const Fixed& point1, const Fixed& point2 );
		friend bool operator<=( const Fixed& point1, const Fixed& point2 );
		friend bool operator==( const Fixed& point1, const Fixed& point2 );
		friend bool operator!=( const Fixed& point1, const Fixed& point2 );
		friend Fixed operator+( const Fixed& point1, const Fixed& point2 );
		friend Fixed operator-( const Fixed& point1, const Fixed& point2 );
		friend Fixed operator*( const Fixed& point1, const Fixed& point2 );
		friend Fixed operator/( const Fixed& point1, const Fixed& point2 );
		Fixed&	operator++( void );		// pre-increment	(++i)
		Fixed	operator++( int );		// post-increment	(i++)
		Fixed&	operator--( void );		// pre-decrement	(--i)
		Fixed	operator--( int );		// post-decrement	(i--)

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:

		static const int	fractional_bits_ = 8;
		static const int	factor_ = 1 << fractional_bits_;
		int 				value_;
	
};

#endif // !FIXED_H
