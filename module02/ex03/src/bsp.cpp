/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:26:13 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/27 11:40:36 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

static Fixed calculateArea( Point const p1, Point const p2, Point const p3 ) {
	Fixed	a1 = p1.getX() * (p2.getY() - p3.getY());
	Fixed	a2 = p2.getX() * (p3.getY() - p1.getY());
	Fixed	a3 = p3.getX() * (p1.getY() - p2.getY());
	Fixed	area = (a1 + a2 + a3) / 2.0f;
	if (area.toFloat() < 0)
		area = area * -1;
	if (a1.toFloat() == 0 || a2.toFloat() == 0 || a3.toFloat() == 0)
		return (area + 42);
	return (area);
}

// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 
bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	triangle = calculateArea(a, b, c);
	Fixed	area1 = calculateArea(point, a, b);	
	Fixed	area2 = calculateArea(point, b, c);
	Fixed	area3 = calculateArea(point, c, a);
	Fixed	sum = area1 + area2 + area3;
	if (sum == triangle) {
		return true;
	} else {
		return false;
	}
}