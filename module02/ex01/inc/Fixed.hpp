/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/20 14:21:04 by joonasmykka      ###   ########.fr       */
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

		static const int	fractional_bits_ = 8;
		static const int	factor_ = 1 << fractional_bits_;
		int 				value_;
	
};

#endif // !FIXED_H
