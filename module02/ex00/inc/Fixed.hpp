/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:38:18 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/20 06:29:58 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

# define EPSILION 1.0e-7

class Fixed {
	
	public:

		Fixed( void );
		Fixed( Fixed const & other );
		Fixed& operator=( Fixed const & other );
		~Fixed ( void );

		int		getRawBits( void );
		void	setRawBits( int const raw );
		
	private:

		static const int	fractional_bits_ = 8;
		int 				value_;
	
};

#endif // !FIXED_H
