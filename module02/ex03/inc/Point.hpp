/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:05:02 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/19 18:07:19 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {
	public:
	
		Point( void );
		Point( float x, float y );
		Point( Point const & other);
		Point& operator=( Point const & other);
		~Point( void );

		Fixed getX( void ) const; 
		Fixed getY( void ) const;
		
	private:
		
		Fixed const	_x;
		Fixed const _y;
		
};

#endif // !POINT_H