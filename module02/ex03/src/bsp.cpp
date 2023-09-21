/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:26:13 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/21 12:00:17 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

static const Fixed EPSILON(0.0039f);

static Fixed crossProduct(Point A, Point B, Point P) {
	Fixed result = (B.getX() - A.getX()) * (P.getY() - A.getY()) - (B.getY() - A.getY()) * (P.getX() - A.getX());

	if (std::abs(result.getRawBits()) < EPSILON.getRawBits())
    	return Fixed(0);
	return result;
}

static bool	OnTheEdge(Point a, Point b, Point c, Point p) {
	Fixed	res1 = crossProduct(a, b, p);
	Fixed	res2 = crossProduct(a, c, p);
	Fixed	res3 = crossProduct(b, c, p);

	return (res1.getRawBits() == 0 || res2.getRawBits() == 0 || res3.getRawBits() == 0);
}

static Fixed calculateArea( Point const p1, Point const p2, Point const p3 ) {
	Fixed	a1 = p1.getX() * (p2.getY() - p3.getY());
	Fixed	a2 = p2.getX() * (p3.getY() - p1.getY());
	Fixed	a3 = p3.getX() * (p1.getY() - p2.getY());
	Fixed	area = (a1 + a2 + a3) / 2.0f;
	
	if (area.toFloat() < 0.0f)
		area = area * -1.0f;
	return (area);
}

// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 
bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	triangle = calculateArea(a, b, c);
	Fixed	area1 = calculateArea(point, a, b);
	Fixed	area2 = calculateArea(point, b, c);
	Fixed	area3 = calculateArea(point, c, a);
	Fixed	sum = area1 + area2 + area3;

	if (OnTheEdge(a, b, c, point))
		return false;
	if (sum == triangle) {
		return true;
	} else {
		return false;
	}
}