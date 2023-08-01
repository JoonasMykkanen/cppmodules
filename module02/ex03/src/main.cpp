/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:27:28 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/27 11:21:16 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );

int main() {
    Point a(0, 0), b(5, 0), c(0, 5);
    
    // Case 1: Point inside triangle
	std::cout << "Case1: inside" << std::endl;
	std::cout << "Expect: true --> got: ";
    Point pointInside(2, 2);
    if(bsp(a, b, c, pointInside)) {
        std::cout << "true" << std::endl;
    } else {
       std::cout << "false" << std::endl;
    }

    // Case 2: Point outside triangle
	std::cout << "Case2: outside" << std::endl;
	std::cout << "Expect: false --> got: ";
    Point pointOutside(10, 10);
    if(bsp(a, b, c, pointOutside)) {
        std::cout << "true" << std::endl;
    } else {
       std::cout << "false" << std::endl;
    }

    // Case 3: Point on the edge of triangle
	std::cout << "Case3: on the edge" << std::endl;
	std::cout << "Expect: false --> got: ";
    Point pointEdge(5, 0);
    if(bsp(a, b, c, pointEdge)) {
       std::cout << "true" << std::endl;
    } else {
       std::cout << "false" << std::endl;
    }

    return 0;
}