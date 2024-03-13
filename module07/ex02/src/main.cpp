/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/13 09:58:11 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/Array.hpp"

int	main( void ) {
	int * a = new int();
	
	Array<int*> myarray(1);

	myarray[0] = a;



	return 0;
} 